#include <iostream>
#include <cmath>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

double distance(int x, int y, int cx, int cy) {
    return sqrt(pow(x - cx, 2) + pow(y - cy, 2));
}

int calculateScore(double dist) {
    if (dist <= 1) return 10;
    if (dist <= 2) return 5;
    return 0;
}

string getLevel(int score) {
    if (score >= 30) return "Снайпер";
    if (score >= 15) return "Просто стрелок";
    return "Новичок";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    srand(time(0));
    int centerX = rand() % 11 - 5;
    int centerY = rand() % 11 - 5;

    int totalScore = 0;
    int shots = 0;
    int targetScore = 50;
    while (totalScore < targetScore) {
        int x, y;
        cout << "Введите координаты выстрела (x, y): ";
        cin >> x >> y;

        double dist = distance(x, y, centerX, centerY);
        int score = calculateScore(dist);
        totalScore += score;
        shots++;

        cout << "Выстрел в точку (" << x << ", " << y << "). Очки: " << score << endl;
        cout << "Общие очки: " << totalScore << endl;
    }

    cout << "Число выстрелов: " << shots << endl;
    cout << "Уровень стрелка: " << getLevel(totalScore) << endl;

    return 0;
}
