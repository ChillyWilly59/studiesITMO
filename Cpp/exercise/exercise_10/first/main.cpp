#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
    cout << "=== Тестирование композиции ===" << endl;

    TriangleComposition triangle1(0, 0, 3, 0, 0, 4);
    triangle1.printSides();
    cout << "Периметр: " << triangle1.perimeter() << endl;
    cout << "Площадь: " << triangle1.area() << endl;

    cout << "\n=== Тестирование агрегации ===" << endl;

    Dot d1(0, 0);
    Dot d2(5, 0);
    Dot d3(0, 12);

    TriangleAggregation triangle2(d1, d2, d3);
    triangle2.printSides();
    cout << "Периметр: " << triangle2.perimeter() << endl;
    cout << "Площадь: " << triangle2.area() << endl;

    return 0;
}