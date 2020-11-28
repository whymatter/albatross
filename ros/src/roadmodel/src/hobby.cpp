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

#define M_SQRT5 2.2360679774997896964091736687313
#define ONE_OVER_16 0.0625

double roh(double a, double b)
{
    return (4.0 + 2.0 * M_SQRT2 * (sin(a) - ONE_OVER_16 * sin(b)) * (sin(b) - ONE_OVER_16 * sin(a)) * (cos(a) - cos(b))) /
           (2.0 + (M_SQRT5 - 1.0) * cos(a) + (3.0 - M_SQRT5) * cos(b));
}

Eigen::MatrixXd splineHobby(const MatrixX2d &knots)
{
    int numKnots = knots.rows();
    int numSections = numKnots - 1;

    /**
     * Calculate \gamma angles and d
    */

    MatrixX2d dv = MatrixXd::Zero(numSections, 2);
    VectorXd dm = VectorXd::Zero(numSections);
    VectorXd gamma = VectorXd::Zero(numKnots); // last gamma is zero, first gamma does not exist

    for (int i = 0; i < numSections; ++i)
    {
        double dx = knots(i + 1, X) - knots(i, X);
        double dy = knots(i + 1, Y) - knots(i, Y);
        dv.row(i) << dx, dy;

        double d = sqrt(dx * dx + dy * dy);
        dm(i) = d;

        if (i > 0)
        {
            double a1 = atan2(dv.row(i - 1).y(), dv.row(i - 1).x());
            double a2 = atan2(dv.row(i).y(), dv.row(i).x());

            double g = a2 - a1;

            // does not fix the problem
//            if (g > M_PI) g = M_PI - g;
//            else if (g < -M_PI) g = -g - M_PI;

            gamma(i) = g;
        }
    }

    ROS_INFO_STREAM("gamma: \n" << gamma);

    /**
     * Calculate \alpha angles
    */

    MatrixXd alphasCoeffizients = MatrixXd::Zero(numKnots, numKnots);
    VectorXd alphasB = VectorXd::Zero(numKnots);

    int iN = numKnots - 1;
    int iN_1 = iN - 1;

    // Add extra equation for: 2 * \alpha_1 + 1 * \alpha_2 = -1 * \gamma_2
    alphasCoeffizients(iN_1, 0) = 2;
    alphasCoeffizients(iN_1, 1) = 1;
    alphasB(iN_1) = -gamma(1);

    // Add extra equation for: \alpha_{n-1} + 2 * \alpha_{n} = -2 * \gamma_{n}
    alphasCoeffizients(iN, iN_1) = 1;
    alphasCoeffizients(iN, iN) = 2;
    alphasB(iN) = 0;

    for (int r = 0; r < iN_1; r++)
    {
        alphasCoeffizients(r, r + 0) = dm(r + 1);
        alphasCoeffizients(r, r + 1) = 2 * dm(r) + 2 * dm(r + 1);
        alphasCoeffizients(r, r + 2) = dm(r);

        alphasB(r) = - (2.0 * gamma(r + 1) * dm(r + 1) + gamma(r + 2) * dm(r));
    }

    VectorXd alpha = alphasCoeffizients.colPivHouseholderQr().solve(alphasB);

    ROS_INFO_STREAM("alphaCoeff: \n" << alphasCoeffizients);
    ROS_INFO_STREAM("B: \n" << alphasB);
    ROS_INFO_STREAM("alpha: \n" << alpha);

    /**
     * Calculate \beta angles
     * \alpha_{n+1} + \beta_n + \gamma_{n+1} = 0
    */

    VectorXd beta = VectorXd::Zero(numKnots);

    // \beta_n is not required
    for (int i = 0; i < numSections; i++)
    {
        beta(i) = -alpha(i + 1) - gamma(i + 1);
    }

    ROS_INFO_STREAM("beta: \n" << beta);

    /**
     * Calculate \roh \sigma
    */

    VectorXd am = VectorXd::Zero(numKnots);
    VectorXd bm = VectorXd::Zero(numKnots);

    // we only need as many alpha/beta/a/b values as there are sections
    for (int i = 0; i < numSections; i++)
    {
        am(i) = roh(alpha(i), beta(i)) * dm(i) / 3.0;
        bm(i) = roh(beta(i), alpha(i)) * dm(i) / 3.0;
    }

    ROS_INFO_STREAM("a: \n" << am);
    ROS_INFO_STREAM("b: \n" << bm);

    /**
     * Calculate control points
    */

    MatrixXd controlPoints = MatrixXd::Zero(numSections * 2, 2);
    MatrixXd rotation = MatrixXd::Zero(2, 2);
    VectorXd controlPoint = VectorXd::Zero(2);
    VectorXd delta = VectorXd::Zero(2);
    VectorXd p0 = VectorXd::Zero(2);
    for (int s = 0; s < numSections; s++)
    {
        delta << dv(s, 0), dv(s, 1);

        double cosAlpha = cos(alpha(s));
        double sinAlpha = sin(alpha(s));
        rotation << cosAlpha, -sinAlpha, sinAlpha, cosAlpha;
        p0 << knots(s, 0), knots(s, 1);
        ROS_INFO_STREAM(p0);
        controlPoint = rotation * delta * 1 / dm(s) * am(s) + p0;
        controlPoints.row(s * 2) << controlPoint(0), controlPoint(1);

        double cosBeta = cos(beta(s));
        double sinBeta = sin(beta(s));
        rotation << cosBeta, sinBeta, -sinBeta, cosBeta;
        p0 << knots(s + 1, 0), knots(s + 1, 1);
        controlPoint = rotation * -delta * 1 / dm(s) * bm(s) + p0;
        controlPoints.row(s * 2 + 1) << controlPoint(0), controlPoint(1);
    }

    ROS_INFO_STREAM("controlPoints: \n" << controlPoints);

    return knots;
}