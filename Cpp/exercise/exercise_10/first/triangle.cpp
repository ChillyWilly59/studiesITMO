#include "triangle.h"
#include <iostream>
#include <cmath>

using namespace std;


TriangleComposition::TriangleComposition()
    : dot1(), dot2(), dot3() {}

TriangleComposition::TriangleComposition(double x1, double y1, double x2, double y2, double x3, double y3)
    : dot1(x1, y1), dot2(x2, y2), dot3(x3, y3) {}

void TriangleComposition::printSides() {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    cout << "Длины сторон треугольника:" << endl;
    cout << "Сторона 1: " << side1 << endl;
    cout << "Сторона 2: " << side2 << endl;
    cout << "Сторона 3: " << side3 << endl;
}

double TriangleComposition::perimeter() {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    return side1 + side2 + side3;
}

double TriangleComposition::area() {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    // Формула Герона
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}


TriangleAggregation::TriangleAggregation(Dot d1, Dot d2, Dot d3)
    : dot1(d1), dot2(d2), dot3(d3) {}

void TriangleAggregation::printSides() {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    cout << "Длины сторон треугольника:" << endl;
    cout << "Сторона 1: " << side1 << endl;
    cout << "Сторона 2: " << side2 << endl;
    cout << "Сторона 3: " << side3 << endl;
}

double TriangleAggregation::perimeter() {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    return side1 + side2 + side3;
}

double TriangleAggregation::area() {
    double side1 = dot1.distanceTo(dot2);
    double side2 = dot2.distanceTo(dot3);
    double side3 = dot3.distanceTo(dot1);

    // Формула Герона
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}