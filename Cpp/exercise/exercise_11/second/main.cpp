#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>



class Point {

    double x;
    double y;

public:
    Point(double xCoord = 0.0, double yCoord = 0.0) : x(xCoord), y(yCoord) {}

    double distanceToOrigin() const {
        return std::sqrt(x * x + y * y);
    }

    double getX() const { return x; }
    double getY() const { return y; }

    bool operator<(const Point& other) const {
        return distanceToOrigin() < other.distanceToOrigin();
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "Point(" << point.x << ", " << point.y << ") - distance: " << point.distanceToOrigin();
        return os;
    }
};

int main() {
    std::cout << "\n=== Тестирование класса Point ===\n";

    std::vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));

    std::sort(v.begin(), v.end());

    std::cout << "После сортировки:\n";
    for (auto &point : v)
        std::cout << point << '\n';

    return 0;
}