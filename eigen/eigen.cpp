#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
int main()
{
    Eigen::MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);

    Eigen::VectorXd v(2);
    v(0) = 2;
    v(1) = 1;

    const Eigen::IOFormat fmt_m(4, 0, ", ", "\n", "[", "]", "m = ", "    ");
    const Eigen::IOFormat fmt_v(4, 0, ", ", "\n", "[", "]", "v = ", "    ");

    std::cout << m.format(fmt_m) << "\n\n";
    std::cout << v.format(fmt_v) << "\n\n"; 

    const Eigen::IOFormat fmt_gen(4, 0, ", ", "\n", "[", "]");
    std::cout << "m * v\n-----\n"
              << (m * v).format(fmt_gen) << "\n\n";
    std::cout << "  4 * m\n---------\n"
              << (4 * m).format(fmt_gen) << "\n\n";
    std::cout << "   v' * m\n------------\n"
              << (v.transpose() * m).format(fmt_gen) << "\n\n";

    return 0;
}