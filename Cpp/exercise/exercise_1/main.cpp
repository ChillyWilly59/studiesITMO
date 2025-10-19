#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

struct Point {
    double x, y;
};

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    // setlocale(LC_ALL, "");

    std::vector<Point> vertices(5);

    std::cout << "Пожалуйста, введите координаты 5 вершин выпуклого пятиугольника (x y):" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Вершина " << i + 1 << " (x): ";
        std::cin >> vertices[i].x;
        std::cout << "Вершина " << i + 1 << " (y): ";
        std::cin >> vertices[i].y;
    }

    double area = 0.0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        area += (vertices[i].x * vertices[j].y) - (vertices[j].x * vertices[i].y);
    }

    area = std::abs(area) / 2.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nПлощадь пятиугольника: " << area << std::endl;

    return 0;
}