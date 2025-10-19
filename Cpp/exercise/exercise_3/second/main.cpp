#include <iostream>
#include <cmath>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif

double cube_root_pow(double a) {
    return pow(a, 1.0 / 3);
}

double cube_root_iterative(double a, int iterations = 100, double tolerance = 1e-6) {
    double x_i = a / 3.0;
    for (int i = 0; i < iterations; ++i) {
        double x_prev = x_i;
        x_i = (1.0 / 3.0) * (a / (x_prev * x_prev) + 2.0 * x_prev);

        if (std::abs(x_i - x_prev) < tolerance) {
            break;
        }
    }
    return x_i;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    double a;
    std::cout << "Введите кубический корень: ";
    std::cin >> a;
    std::cout << "Кубический корень числа " << a << " с использованием pow: " << cube_root_pow(a) << std::endl;
    std::cout << "Кубический корень числа " << a << " с использованием итерационного метода: " << cube_root_iterative(a) << std::endl;
    return 0;
}
