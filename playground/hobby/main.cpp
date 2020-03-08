#include <math.h>
#include <iostream>
#include <vector>
#include <Eigen/Dense>

#define M_SQRT5 2.2360679774997896964091736687313
#define M_1_16 0.0625

#define P(a, b) velocity(a, b)
#define O(a, b) velocity(b, a)

using Eigen::MatrixXd;

/*

var s = `Eigen::MatrixXf m(${pointsX.length}, 2);\nm << `; for (var i = 0; i < pointsX.length; i++) s += pointsX[i] + ", " + pointsY[i] + (i == pointsX.length-1 ? ";" : ",\n")

http://weitz.de/hobby/


*/

float velocity(float a, float b)
{
    float cosa = cosf(a);
    float cosb = cosf(b);

    float sina = sinf(a);
    float sinb = sinf(b);

    return (4. + 2. * M_SQRT2 * (sina - M_1_16 * sinb) * (sinb - M_1_16 * sina) * (cosa - cosb)) /
           (2. + (M_SQRT5 - 1) * cosa + (3. - M_SQRT5) * cosb);
}

Eigen::MatrixXf calcVectors(Eigen::MatrixXf m)
{
    Eigen::MatrixXf v = Eigen::MatrixXf::Zero(m.rows() - 1, 2);
    for (int i = 1; i < m.rows(); i++)
    {
        float dx = m(i, 0) - m(i - 1, 0);
        float dy = m(i, 1) - m(i - 1, 1);

        v(i - 1, 0) = dx;
        v(i - 1, 1) = dy;
    }

    return v;
}

Eigen::VectorXf calcDistances(Eigen::MatrixXf m)
{
    Eigen::VectorXf d = Eigen::VectorXf::Zero(m.rows());

    for (int i = 0; i < m.rows(); i++)
    {
        d[i] = sqrtf(m(i, 0) * m(i, 0) + m(i, 1) * m(i, 1));
    }

    return d;
}

Eigen::VectorXf calcAngles(Eigen::MatrixXf m, Eigen::VectorXf d)
{
    assert(m.rows() == d.rows());

    Eigen::VectorXf a = Eigen::VectorXf::Zero(m.rows() + 1);

    for (int i = 1; i < m.rows(); i++)
    {
        // credtig goes to: https://de.mathworks.com/matlabcentral/answers/180131-how-can-i-find-the-angle-between-two-vectors-including-directional-information
        float x1 = m(i - 1, 0);
        float y1 = m(i - 1, 1);

        float x2 = m(i, 0);
        float y2 = m(i, 1);

        a[i] = atan2f(x1 * y2 - y1 * x2, x1 * x2 + y1 * y2);
    }

    // last angle is zero

    return a;
}

// Vectors a, b, c and d are const. They will not be modified
// by the function. Vector f (the solution vector) is non-const
// and thus will be calculated and updated by the function.
void thomas_algorithm(const Eigen::VectorXf &a,
                      const Eigen::VectorXf &b,
                      const Eigen::VectorXf &c,
                      const Eigen::VectorXf &d,
                      Eigen::VectorXf &x)
{
    Eigen::Index N = c.rows();

    // Create the temporary vectors
    // Note that this is inefficient as it is possible to call
    // this function many times. A better implementation would
    // pass these temporary matrices by non-const reference to
    // save excess allocation and deallocation
    std::vector<float> c_star(N, 0.0);
    std::vector<float> d_star(N, 0.0);

    // This updates the coefficients in the first row
    // Note that we should be checking for division by zero here
    c_star[0] = c[0] / b[0];
    d_star[0] = d[0] / b[0];

    // Create the c_star and d_star coefficients in the forward sweep
    for (int i = 1; i < N; i++)
    {

        float m = (b[i] - a[i] * c_star[i - 1]);
        c_star[i] = c[i] / m;
        d_star[i] = (d[i] - a[i] * d_star[i - 1]) / m;
    }

    // This is the reverse sweep, used to update the solution vector f
    x[N - 1] = d_star[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        x[i] = d_star[i] - c_star[i] * x[i + 1];
    }
}

void solveAlpha(const Eigen::VectorXf &d, const Eigen::VectorXf &g, Eigen::VectorXf &alpha)
{
    assert(d.rows() + 1 == g.rows());

    Eigen::Index N = g.rows();

    Eigen::VectorXf a = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf b = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf c = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf dd = Eigen::VectorXf::Zero(N);

    for (int i = 1; i < (N - 1); i++)
    {
        a[i] = 1 / d[i - 1];
        b[i] = (2 * d[i - 1] + 2 * d[i]) / (d[i - 1] * d[i]);
        c[i] = 1 / d[i];
        dd[i] = -(2 * g[i] * d[i] + g[i + 1] * d[i - 1]) / (d[i - 1] * d[i]);
    }

    float omega = 1.;
    b[0] = 2. + omega;
    c[0] = 2. * omega + 1.;
    dd[0] = -c[0] * g[1];
    a[N - 1] = 2. * omega + 1.;
    b[N - 1] = 2. + omega;
    dd[N - 1] = 0.;

    thomas_algorithm(a, b, c, dd, alpha);
}

int main()
{
    Eigen::MatrixXf m(9, 2);
    m << 61.21672821044922, 309.6958312988281,
        263.11785888671875, 680.9885864257812,
        509.5057067871094, 653.6121826171875,
        807.2243041992188, 415.77947998046875,
        300.7604675292969, 424.3345947265625,
        141.63497924804688, 723.7642822265625,
        206.65399169921875, 290.87451171875,
        182.69961547851562, 545.8175048828125,
        839.7338256835938, 602.2813720703125;

    Eigen::Index N = m.rows();

    // test velocity function
    float test = P(1.2, 0.5) - O(0.5, 1.2);
    printf("test [should be 0]: %f\n", test);

    // calculate vectors
    Eigen::MatrixXf v = calcVectors(m);
    std::cout << "Vectors:" << std::endl;
    std::cout << v << std::endl;

    // calculate distances
    Eigen::VectorXf d = calcDistances(v);
    std::cout << "Distances:" << std::endl;
    std::cout << d << std::endl;

    // calculate angles
    Eigen::VectorXf g = calcAngles(v, d);
    std::cout << "Gamma Angles:" << std::endl;
    std::cout << g << std::endl;

    // prepare thomas algorithm
    Eigen::VectorXf alpha = Eigen::VectorXf::Zero(N);
    solveAlpha(d, g, alpha);
    std::cout << "Alpha Angles:" << std::endl;
    std::cout << alpha << std::endl;

    // calculate beta, a, b, sx, sy
    Eigen::VectorXf beta = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf a = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf b = Eigen::VectorXf::Zero(N);

    Eigen::VectorXf sx1 = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf sy1 = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf sx2 = Eigen::VectorXf::Zero(N);
    Eigen::VectorXf sy2 = Eigen::VectorXf::Zero(N);

    for (int i = 0; i < N - 1; i++)
    {
        if (i < N - 2)
        {
            beta[i] = -alpha[i + 1] - g[i + 1];
        }
        else
        {
            beta[i] = -alpha[N - 1];
        }

        a[i] = P(alpha[i], beta[i]) * d[i] / 3.;
        b[i] = O(alpha[i], beta[i]) * d[i] / 3.;

        Eigen::Vector2f t(v(i, 0), v(i, 1));

        Eigen::Vector2f v1(m(i, 0), m(i, 1));
        Eigen::Vector2f v2(m(i + 1, 0), m(i + 1, 1));

        Eigen::Rotation2D<float> rotAlpha(alpha[i]);
        Eigen::Rotation2D<float> rotBeta(-beta[i]);

        Eigen::Vector2f t1 = v1 + (rotAlpha * t).normalized() * a[i];
        Eigen::Vector2f t2 = v2 - (rotBeta * t).normalized() * b[i];

        sx1[i] = t1(0);
        sy1[i] = t1(1);
        sx2[i] = t2(0);
        sy2[i] = t2(1);
    }

    std::cout << "Beta Angles:" << std::endl;
    std::cout << beta << std::endl;

    std::cout << "a:" << std::endl;
    std::cout << a << std::endl;

    std::cout << "b:" << std::endl;
    std::cout << b << std::endl;

    // print html stuff for chrome

    std::cout << "var canvas = document.createElement('canvas');\n"
              << "\n"
              << "document.body = document.createElement('body');\n"
              << "document.body.append(canvas);\n"
              << "\n"
              << "canvas.width = document.body.clientWidth;\n"
              << "canvas.height = document.body.clientHeight;\n"
              << "\n"
              << "var ctx = canvas.getContext('2d');\n"
              << "\n"
              << "ctx.beginPath();\n"
              << "\n";

    std::ostringstream bezierString;
    std::ostringstream pointString;

    bezierString << "ctx.moveTo(" << m(0, 0) << "," << m(0, 1) << ");\n\n";
    pointString << "ctx.beginPath(); ctx.arc("
                << m(0, 0) << "," << m(0, 1)
                << ", 5, 0, 2 * Math.PI, false); ctx.fill();\n";

    for (int i = 0; i < N - 1; i++)
    {
        bezierString << "ctx.bezierCurveTo("
                     << sx1(i) << "," << sy1(i) << ","
                     << sx2(i) << "," << sy2(i) << ","
                     << m(i + 1, 0) << "," << m(i + 1, 1) << ");\n";

        pointString << "ctx.beginPath(); ctx.arc("
                    << m(i + 1, 0) << "," << m(i + 1, 1)
                    << ", 5, 0, 2 * Math.PI, false); ctx.fill();\n";
    }

    bezierString << "\nctx.stroke();\n\n";

    std::cout << bezierString.str() << pointString.str();

    return 0;
}