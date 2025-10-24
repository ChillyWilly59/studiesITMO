#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;

tuple<double, double, bool> solveQuadraticWithTuple(double a, double b, double c) {
    double root1, root2;
    bool hasRoots = true;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
    } else {
        hasRoots = false;
        root1 = root2 = NAN;
    }

    return make_tuple(root1, root2, hasRoots);
}

int main() {
    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    auto [root1, root2, hasRoots] = solveQuadraticWithTuple(a, b, c);

    if (!hasRoots) {
        cout << "Нет реальных корней." << endl;
    } else if (root1 == root2) {
        cout << "Один корень: " << root1 << endl;
    } else {
        cout << "Корни: " << root1 << " и " << root2 << endl;
    }

    return 0;
}
