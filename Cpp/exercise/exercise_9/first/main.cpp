#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3) {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            throw invalid_argument("Стороны треугольника должны быть положительными.");
        }
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            throw invalid_argument("Стороны не могут образовать треугольник.");
        }
        a = side1;
        b = side2;
        c = side3;
    }

    double area() const {
        double s = (a + b + c) / 2.0;  // Полупериметр
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    try {
        double a, b, c;
        cout << "Введите три стороны треугольника: ";
        cin >> a >> b >> c;
        Triangle t(a, b, c);
        cout << "Площадь треугольника: " << t.area() << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
