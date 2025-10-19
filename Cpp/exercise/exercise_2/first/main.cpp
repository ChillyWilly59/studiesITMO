#include <iostream>
#include <cmath>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif


bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSuperPrime(int n) {

    if (!isPrime(n)) return false;
    std::string numStr = std::to_string(n);
    numStr.erase(0, 1);

    int remainingNum = std::stoi(numStr);

    return isPrime(remainingNum);
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;

    if (isSuperPrime(num)) {
        std::cout << num << " является суперпростым числом.\n";
    } else {
        std::cout << num << " не является суперпростым числом.\n";
    }

    return 0;
}
