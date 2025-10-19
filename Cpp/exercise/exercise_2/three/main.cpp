#include <iostream>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    vector<int> coins = {10, 5, 2, 1};

    int amount;
    cout << "Введите сумму: ";
    cin >> amount;

    int coinCount = 0;

    for (int coin : coins) {
        if (amount >= coin) {
            coinCount += amount / coin;
            amount %= coin;
        }
    }

    cout << "Минимальное количество монет: " << coinCount << endl;

    return 0;
}
