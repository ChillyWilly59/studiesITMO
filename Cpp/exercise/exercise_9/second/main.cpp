#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60 || seconds < 0) {
            throw invalid_argument("Неверное количество секунд.");
        }
        if (minutes >= 60 || minutes < 0) {
            throw invalid_argument("Неверное количество минут.");
        }
        if (hours < 0) {
            throw invalid_argument("Часы не могут быть отрицательными.");
        }
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds;
    }

    Time add(const Time& other) const {
        Time result(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
        result.normalize();
        return result;
    }
};

int main() {
    try {
        int h, m, s;
        cout << "Введите время (часы минуты секунды): ";
        cin >> h >> m >> s;
        Time t1(h, m, s);
        cout << "Введите время для сложения (часы минуты секунды): ";
        cin >> h >> m >> s;
        Time t2(h, m, s);

        Time t3 = t1.add(t2);
        cout << "Результат сложения: ";
        t3.display();
        cout << endl;

    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
