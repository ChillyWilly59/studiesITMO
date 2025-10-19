#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int recursion(int a) {
    if (a==1)
        return 5;
    return 5 * a + recursion(a -1);
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int n;
    std::cout <<  "Введите значение n: ";
    std::cin >> n;

    if (n>0) {
        int result = recursion(n);
        std::cout << "Суммв ряда для n = " << n << ": " << result << std::endl;
    }else {
        std::cout << "Введите n > 0." << std::endl;
    }

    return 0;
}