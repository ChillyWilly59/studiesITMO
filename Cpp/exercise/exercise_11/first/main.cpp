#include <iostream>
#include <string>
#include <cmath>

class Time {
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

        if (hours < 0) {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    double toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    static Time fromSeconds(double totalSeconds) {
        int h = static_cast<int>(totalSeconds) / 3600;
        int m = (static_cast<int>(totalSeconds) % 3600) / 60;
        int s = static_cast<int>(totalSeconds) % 60;
        return Time(h, m, s);
    }

    Time operator+(const Time& other) const {
        return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
    }

    Time operator-(const Time& other) const {
        return Time(hours - other.hours, minutes - other.minutes, seconds - other.seconds);
    }

    Time operator+(double secondsToAdd) const {
        return fromSeconds(toSeconds() + secondsToAdd);
    }

    friend Time operator+(double secondsToAdd, const Time& time) {
        return time + secondsToAdd;
    }

    bool operator==(const Time& other) const { return toSeconds() == other.toSeconds(); }
    bool operator!=(const Time& other) const { return !(*this == other); }
    bool operator<(const Time& other) const { return toSeconds() < other.toSeconds(); }
    bool operator>(const Time& other) const { return toSeconds() > other.toSeconds(); }
    bool operator<=(const Time& other) const { return toSeconds() <= other.toSeconds(); }
    bool operator>=(const Time& other) const { return toSeconds() >= other.toSeconds(); }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << time.hours << ":" << time.minutes << ":" << time.seconds;
        return os;
    }
};
int main() {
    std::cout << "=== Тестирование класса Time ===\n";

    Time t1(2, 30, 45);
    Time t2(1, 45, 20);

    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;

    Time sum = t1 + t2;
    std::cout << "t1 + t2 = " << sum << std::endl;

    Time diff = t1 - t2;
    std::cout << "t1 - t2 = " << diff << std::endl;

    Time t3 = t1 + 125.5;
    std::cout << "t1 + 125.5 сек = " << t3 << std::endl;

    Time t4 = 180.7 + t2;
    std::cout << "180.7 сек + t2 = " << t4 << std::endl;

    std::cout << "\nСравнение:\n";
    std::cout << "t1 == t2: " << (t1 == t2 ? "true" : "false") << std::endl;
    std::cout << "t1 != t2: " << (t1 != t2 ? "true" : "false") << std::endl;
    std::cout << "t1 < t2: " << (t1 < t2 ? "true" : "false") << std::endl;
    std::cout << "t1 > t2: " << (t1 > t2 ? "true" : "false") << std::endl;

}