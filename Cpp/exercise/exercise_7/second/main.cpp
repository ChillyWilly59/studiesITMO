#include <iostream>
#include <cmath>
using namespace std;

struct QuadraticSolution {
    double root1;
    double root2;
};

QuadraticSolution solveQuadratic(double a, double b, double c) {
    QuadraticSolution solution;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
        solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        solution.root1 = solution.root2 = -b / (2 * a);
    } else {
        solution.root1 = solution.root2 = NAN;
    }

    return solution;
}

int main() {
    double a, b, c;
    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    QuadraticSolution solution = solveQuadratic(a, b, c);

    if (isnan(solution.root1)) {
        cout << "Нет реальных корней." << endl;
    } else if (solution.root1 == solution.root2) {
        cout << "Один корень: " << solution.root1 << endl;
    } else {
        cout << "Корни: " << solution.root1 << " и " << solution.root2 << endl;
    }

    return 0;
}
