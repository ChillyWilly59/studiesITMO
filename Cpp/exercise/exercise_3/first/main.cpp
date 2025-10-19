#include <iostream>
#include <string>
#include <cctype>
#ifdef _WIN32
#include <windows.h>
#endif

bool isValidSNILS(const std::string& input) {
    std::string snils = "";
    for (char ch : input) {
        if (isdigit(ch)) {
            snils += ch;
        } else if (ch != ' ' && ch != '-') {
            return false;
        }
    }

    if (snils.length() != 11) {
        return false;
    }

     std::string mainPart = snils.substr(0, 9);
    int controlNumber = std::stoi(snils.substr(9, 2));

    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (mainPart[i] - '0') * (9 - i);
    }

    int calculatedControl = 0;
    if (sum < 100) {
        calculatedControl = sum;
    } else if (sum == 100 || sum == 101) {
        calculatedControl = 0;
    } else {
        int remainder = sum % 101;
        if (remainder < 100) {
            calculatedControl = remainder;
        } else {
            calculatedControl = 0;
        }
    }

    return calculatedControl == controlNumber;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::string snils;
    std::cout << "Введите номер СНИЛС: ";
    std::cin >> snils;

    if (isValidSNILS(snils)) {
        std::cout << "Номер СНИЛС является валидным.\n";
    } else {
        std::cout << "Номер СНИЛС является неверным.\n";
    }

    return 0;
}
