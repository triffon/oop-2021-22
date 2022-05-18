#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Time {
    int hour;
    int minute;

    void setHour(int hour) {
        if (hour >= 0 && hour <= 23) {
            this->hour = hour;
        } else {
            this->hour = 0;
        }
    }

    void setMinute(int minute) {
        if (minute >= 0 && minute <= 60) {
            this->minute = minute;
        } else {
            this->minute = 0;
        }
    }

public:
    Time() {
        setHour(0);
        setMinute(0);
    }

    Time(int hour, int minute) {
        setHour(hour);
        setMinute(minute);
    }

    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    Time operator+(const Time& t) {
        int newHour = (hour + t.getHour() + (minute + t.getMinute()) / 60 ) % 24;
        int newMinute = (minute + t.getMinute()) % 60;
        Time result(newHour, newMinute);
        return result;
    }

    Time operator+(int hour) {
        int newHour = (this->hour + hour) % 24;
        Time result(newHour, this->minute);
        return result;
    }

    Time& operator=(const Time& t) {
        this->hour = t.getHour();
        this->minute = t.getMinute();
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, Time& t);
    friend std::ostream& operator<<(std::ostream& out, const Time& t);

    void print() {
        if (hour < 10) cout << "0";
        cout << hour << ":";
        if (minute < 10) cout << "0";
        cout << minute << endl;
    }

    friend Time operator+(int hour, const Time& t);
};

std::istream& operator>>(std::istream& in, Time& t) {
    in >> t.hour >> t.minute;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << "Time: " << t.hour << ':' << t.minute << '/n';
    return out;
}

Time operator+(int hour, const Time& t) {
    int newHour = (t.getHour() + hour) % 24;
    Time result(newHour, t.getMinute());
    return result;
}
