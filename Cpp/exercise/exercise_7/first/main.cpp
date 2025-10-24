#include <iostream>
using namespace std;

struct Time {
    int hours;
    int minutes;
    int seconds;

    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time add(const Time& other) const {
        Time result;
        int total_seconds = toSeconds() + other.toSeconds();
        result.hours = total_seconds / 3600;
        result.minutes = (total_seconds % 3600) / 60;
        result.seconds = total_seconds % 60;
        return result;
    }

    Time subtract(const Time& other) const {
        Time result;
        int total_seconds = toSeconds() - other.toSeconds();
        if (total_seconds < 0) {
            result.hours = result.minutes = result.seconds = 0;
        } else {
            result.hours = total_seconds / 3600;
            result.minutes = (total_seconds % 3600) / 60;
            result.seconds = total_seconds % 60;
        }
        return result;
    }
};

int main() {
    Time t1, t2;

    cout << "Введите время (часы минуты секунды): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "Введите другое время (часы минуты секунды): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    cout << "Первое время в секундах: " << t1.toSeconds() << endl;
    cout << "Второе время в секундах: " << t2.toSeconds() << endl;

    Time t3 = t1.add(t2);
    cout << "Сложение: " << t3.hours << " ч " << t3.minutes << " мин " << t3.seconds << " сек" << endl;

    Time t4 = t1.subtract(t2);
    cout << "Вычитание: " << t4.hours << " ч " << t4.minutes << " мин " << t4.seconds << " сек" << endl;

    return 0;
}
