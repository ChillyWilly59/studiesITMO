#include <iostream>
#include <cmath>

using namespace std;

int Myroot(double a, double b, double c, double x1, double x2) {
    double D = b * b - 4 * a * c;

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        return 1;
    }
    else if (D == 0) {
        x1 = x2 = -b / (2 * a);
        return 0;
    }
    else {
        return -1;
    }
};

int main() {


    double a, b, c;
    double x1, x2;

    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;

    int result = Myroot(a, b, c, x1, x2);

    if (result == -1) {
        cout << "There are no roots.\n";
    } else if (result == 0) {
        cout << "One root of the equation: x1 = x2 = " << x1 << endl;
    } else {
        cout << "Roots of the equation: x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    return 0;
}
