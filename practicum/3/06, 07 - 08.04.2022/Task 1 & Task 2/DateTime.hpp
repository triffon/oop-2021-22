#pragma once

#include <iostream>

class DateTime {
    int day;
    int month;
    int year;
    int hour;
    int minutes;

  public:
    DateTime();
    DateTime(int day, int month, int year, int hour, int minutes);

    int getDay() const;
    void setDay(int day);

    int getMonth() const;
    void setMonth(int month);

    int getYear() const;
    void setYear(int year);

    int getHour() const;
    void setHour(int hour);

    int getMinutes() const;
    void setMinutes(int minutes);

    void serialize(std::ostream &out) const;
    void deserialize(std::istream &in);

    DateTime operator+(const DateTime &o) const;
    void operator+=(const DateTime &o);

    friend std::istream &operator>>(std::istream &in, DateTime &d);
    friend std::ostream &operator<<(std::ostream &out, const DateTime &d);
};
