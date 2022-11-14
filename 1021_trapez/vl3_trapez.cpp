#include <iostream>
#include <cmath>

double trapez(double (*f)(double), double a, double b, int n)
{
    double step{(b - a) / n};
    double sum;
    for (int i = 1; i < n; ++i)
    {
        sum += f(a + i * step);
    }
    return (((f(a) + f(b)) / 2) + sum) * step;
}

double f(double x)
{
    return std::sqrt(x) / (1 + 2 * x);
}

int main(void)
{
    std::cout << "Integral1: " << trapez(f, 10, 20, 1000) << std::endl;
    std::cout << "Integral2: " << trapez(std::sin, 0, 4 * 3.14159265358979, 1000) << std::endl;
    // prototype
    double (*f)(double);
    // type definition
    using t_func_ptr = double (*)(double);
    t_func_ptr af[4] = {std::sin, std::atan, std::sqrt, std::cos};
    for (t_func_ptr func : af)
    {
        std::cout << "Integral: " << trapez(func, 0, 4 * 3.14159265358979, 1000) << std::endl;
    }
    t_func_ptr *af_d = new t_func_ptr[4]{std::sin, std::atan, std::sqrt, std::cos};
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Integral: " << trapez(af_d[i], 0, 4 * 3.14159265358979, 1000) << std::endl;
    }
    return 0;
}
