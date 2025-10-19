#include <iostream>
#include <cmath>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

double calculateArea(double a) {
    return (sqrt(3) / 4) * a * a;
}

double calculateArea(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int choice;

    cout << "Выберите тип треугольника:\n";
    cout << "1. Равносторонний треугольник\n";
    cout << "2. Разносторонний треугольник\n";
    cout << "Ваш выбор (1 или 2): ";
    cin >> choice;

    if (choice == 1) {
        double side;
        cout << "Введите сторону равностороннего треугольника: ";
        cin >> side;
        double area = calculateArea(side);
        cout << "Площадь равностороннего треугольника: " << area << endl;
    }
    else if (choice == 2) {
        double a, b, c;
        cout << "Введите стороны разностороннего треугольника:\n";
        cout << "Сторона a: ";
        cin >> a;
        cout << "Сторона b: ";
        cin >> b;
        cout << "Сторона c: ";
        cin >> c;

        if (a + b > c && a + c > b && b + c > a) {
            double area = calculateArea(a, b, c);
            cout << "Площадь разностороннего треугольника: " << area << endl;
        } else {
            cout << "Такой треугольник не существует.\n";
        }
    }
    else {
        cout << "Неверный выбор. Пожалуйста, выберите 1 или 2.\n";
    }

    return 0;
}
