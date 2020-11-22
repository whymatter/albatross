//
// Created by seitz on 11/20/20.
//

#include "spline.h"

Eigen::MatrixXd spline(const MatrixX2d &knots) {
    int numKnots = knots.rows();
    int numSections = numKnots - 1;

    VectorXd h(numSections);
    VectorXd delta(numSections);
    VectorXd right(numKnots);
    MatrixXd cMatrix = MatrixXd::Zero(numKnots, numKnots);
    VectorXd a(numKnots);
    VectorXd b(numKnots);
    VectorXd c(numKnots);
    VectorXd d(numKnots);

    // calculate h and delta
    for (int i = 0; i < numSections; ++i) {
        double h1 = knots(i + 1, 0);
        double h2 = knots(i, 0);
        h(i) = h2 < h1 ? h1 - h2 : h2 - h1;
        const double &d1 = knots(i + 1, 1);
        const double &d2 = knots(i, 1);
        delta(i) = (h2 < h1 ? d1 - d2 : d2 - d1) / h(i);
    }

//    ROS_INFO_STREAM("h:" << std::endl << h);
//    ROS_INFO_STREAM("delta:" << std::endl << delta);

    // calculate the right side of the matrix for the calculation of c
    right(0) = 0;
    for (int i = 1; i < numKnots - 1; i++) {
        right(i) = 3 * (delta(i) - delta(i - 1));
    }
    right(numKnots - 1) = 0;

//    ROS_INFO_STREAM("right:" << std::endl << right);

    // calculate the matrix used for calculating c
    // when using natural spline mode then the first row and last contain the hard coded values from above
    // further initializations of the first and last row are not needed
    cMatrix(0, 0) = 1;
    cMatrix(0, 1) = 0;
    for (int y = 1; y < numKnots - 1; y++) {
        // letters correspond to https://de.wikipedia.org/wiki/Thomas-Algorithmus
        cMatrix(y, (y - 1)) = h(y - 1); // a
        cMatrix(y, y) = 2 * (h(y - 1) + h(y)); // b
        cMatrix(y, (y + 1)) = h(y); // c
    }
    cMatrix(numKnots - 1, numKnots - 2) = 0;
    cMatrix(numKnots - 1, numKnots - 1) = 1;

//    ROS_INFO_STREAM("cMatrix:" << std::endl << cMatrix);

//    auto start = std::chrono::high_resolution_clock::now();
    // those steps are just for verification of the result
    VectorXd x = cMatrix.colPivHouseholderQr().solve(right);
//    ROS_INFO_STREAM("x by qr:" << std::endl << x);
//    auto finish = std::chrono::high_resolution_clock::now();
//    std::chrono::duration<double> elapsed = finish - start;
//    ROS_INFO_STREAM("Elapsed time for QR: " << elapsed.count());

//    start = std::chrono::high_resolution_clock::now();
    // Do the 'forward pass' https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm
    cMatrix(0, 1) /= cMatrix(0, 0);
    for (int y = 1; y < numKnots - 1; y++) {
        cMatrix(y, (y + 1)) /= (cMatrix(y, y) - cMatrix(y - 1, y) * cMatrix(y, y - 1)); // c / (b - c' * a)
    }

//    ROS_INFO_STREAM("cMatrix:" << std::endl << cMatrix);

    // Do the 'forward pass' https://en.wikipedia.org/wiki/Tridiagonal_matrix_algorithm
    right(0) /= cMatrix(0, 0);
    for (int y = 1; y < numKnots; y++) {
        double z = right(y) - right(y - 1) * cMatrix(y, (y - 1)); // (d - d' * a)
        double n = (cMatrix(y, y) - cMatrix(y - 1, y) * cMatrix(y, y - 1)); // (b - c' * a)
        right(y) = z / n;
    }

//    ROS_INFO_STREAM("right:" << std::endl << right);

    // calculate c values
    c(numKnots - 1) = right(numKnots - 1);
    for (int i = numKnots - 2; i >= 0; i--) {
        c(i) = right(i) - cMatrix(i, (i + 1)) * c(i + 1);
    }

    // c has to equal x (x was solved for testing by using qr decomposition)
    ROS_INFO_STREAM("c:" << std::endl << c);
//    finish = std::chrono::high_resolution_clock::now();
//    elapsed = finish - start;
//    ROS_INFO_STREAM("Elapsed time for Thomas: " << elapsed.count());

    // calculate d values
    for (int i = 0; i < numKnots - 1; i++) {
        d(i) = (c(i + 1) - c(i)) / (3 * h(i));
    }
    ROS_INFO_STREAM("d:" << std::endl << d);

    // calculate b values
    for (int i = 0; i < numKnots - 1; i++) {
        b(i) = delta(i) - (h(i) / 3) * (2 * c(i) + c(i + 1));
    }
    ROS_INFO_STREAM("b:" << std::endl << b);

    // calculate a values
    for (int i = 0; i < numKnots; i++) {
        a(i) = knots(i, 1);
    }
    ROS_INFO_STREAM("a:" << std::endl << a);

    MatrixXd result = MatrixXd::Zero(numKnots, 4);
    result.col(0) = a;
    result.col(1) = b;
    result.col(2) = c;
    result.col(3) = d;

    return result;
}
