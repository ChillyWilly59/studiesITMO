#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        } else if (seconds < 0) {
            int borrow = (abs(seconds) + 59) / 60;
            minutes -= borrow;
            seconds += borrow * 60;
        }

        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        } else if (minutes < 0) {
            int borrow = (abs(minutes) + 59) / 60;
            hours -= borrow;
            minutes += borrow * 60;
        }

        if (hours < 0) hours = 0;
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) { normalize(); }

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds;
    }

    Time add(const Time& other) const {
        Time result;
        result.seconds = seconds + other.seconds;
        result.minutes = minutes + other.minutes;
        result.hours = hours + other.hours;
        result.normalize();
        return result;
    }
};

int main() {
    const Time t1(1, 70, 80);
    const Time t2(0, 50, 45);
    Time t3;

    cout << "Первое время: ";
    t1.display();
    cout << endl;

    cout << "Второе время: ";
    t2.display();
    cout << endl;

    t3 = t1.add(t2);

    cout << "Сумма: ";
    t3.display();
    cout << endl;

    return 0;
}
