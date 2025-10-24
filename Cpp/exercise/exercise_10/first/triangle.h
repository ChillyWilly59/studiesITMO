#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "dot.h"

class TriangleComposition
{
private:
    Dot dot1, dot2, dot3;
public:
    TriangleComposition();
    TriangleComposition(double x1, double y1, double x2, double y2, double x3, double y3);

    void printSides();
    double perimeter();
    double area();
};

class TriangleAggregation
{
private:
    Dot dot1, dot2, dot3;

public:
    TriangleAggregation(Dot d1, Dot d2, Dot d3);

    // Методы
    void printSides();
    double perimeter();
    double area();
};

#endif