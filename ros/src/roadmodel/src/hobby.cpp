//
// Created by seitz on 11/21/20.
//

#include <math.h>

#include "hobby.h"

// x1 | y1
// x2 | y2
// x3 | y3

#define X 0
#define Y 1

Eigen::MatrixXd splineHobby(const MatrixX2d &knots) {
    int numKnots = knots.rows();
    int numSections = numKnots - 1;

    MatrixX2d dv = MatrixXd::Zero(numSections, 2);
    VectorXd dm = VectorXd::Zero(numSections);
    VectorXd ya = VectorXd::Zero(numSections - 1);

    for (int i = 0; i < numSections; ++i) {
        double dx = knots(i + 1, X) - knots(i, X);
        double dy = knots(i + 1, Y) - knots(i, Y);
        dv.row(i) << dx, dy;

        double d = sqrt(dx * dx + dy * dy);
        dm(i) = d;

        if (i > 0) {
            double scalarProduct = dv.row(i - 1).x() * dv.row(i).x() +
                                   dv.row(i - 1).y() * dv.row(i).y();
            double a = acos(scalarProduct / (dm.row(i - 1) * dm.row(i)));
            ya(i - 1) = a;

            ROS_INFO_STREAM("y: " << ya);
        }
    }

    return knots;
}