#include <iostream>
#include <string>
#include <cctype>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    string input;
    cout << "Введите номер СНИЛС (11 цифр): ";
    cin >> input;

    if (input.length() != 11) {
        cout << "False" << endl;
        return 0;
    }

    for (char ch : input) {
        if (!isdigit(ch)) {
            cout << "False" << endl;
            return 0;
        }
    }

     for (int i = 0; i < 7; ++i) {
        if (input[i] == input[i+1] && input[i+1] == input[i+2]) {
            cout << "False" << endl;
            return 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        int digit = input[i] - '0';
        sum += digit * (9 - i);
    }

    int control = 0;
    if (sum < 100) {
        control = sum;
    } else if (sum == 100 || sum == 101) {
        control = 0;
    } else {
        int remainder = sum % 101;
        if (remainder < 100) {
            control = remainder;
        } else {
            control = 0;
        }
    }

    int inputControl = stoi(input.substr(9, 2));

    if (control == inputControl) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
