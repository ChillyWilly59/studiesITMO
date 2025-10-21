#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Ошибка: недостаточно параметров!" << endl;
        return 1;
    }

    if (strncmp(argv[1], "-a", 2) == 0 || strncmp(argv[1], "-m", 2) == 0) {
        int num1 = atoi(argv[2]);
        int num2 = atoi(argv[3]);

        if (num1 == 0 && argv[2][0] != '0') {
            cout << "Ошибка: некорректный первый операнд!" << endl;
            return 1;
        }

        if (num2 == 0 && argv[3][0] != '0') {
            cout << "Ошибка: некорректный второй операнд!" << endl;
            return 1;
        }

        if (strncmp(argv[1], "-a", 2) == 0) {
            cout << "Результат (сумма): " << num1 + num2 << endl;
        } else if (strncmp(argv[1], "-m", 2) == 0) {
            cout << "Результат (произведение): " << num1 * num2 << endl;
        }
    } else {
        cout << "Ошибка: некорректный флаг. Используйте -a для суммы или -m для произведения." << endl;
        return 1;
    }

    return 0;
}
