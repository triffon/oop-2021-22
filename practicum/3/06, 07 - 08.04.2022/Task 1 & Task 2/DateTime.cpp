#include "DateTime.hpp"

#include <iomanip>

DateTime::DateTime() {
    this->day = 0;
    this->month = 0;
    this->year = 0;
    this->hour = 0;
    this->minutes = 0;
}

DateTime::DateTime(int day, int month, int year, int hour, int minutes) : DateTime() {
    this->setDay(day);
    this->setMonth(month);
    this->setYear(year);
    this->setHour(hour);
    this->setMinutes(minutes);
}

int DateTime::getDay() const {
    return this->day;
}

void DateTime::setDay(int day) {
    if (day > 0 && day <= 31)
        this->day = day;
}

int DateTime::getMonth() const {
    return this->month;
}

void DateTime::setMonth(int month) {
    if (month >= 1 && month <= 12)
        this->month = month;
}

int DateTime::getYear() const {
    return this->year;
}

void DateTime::setYear(int year) {
    if (year > 0)
        this->year = year;
}

int DateTime::getHour() const {
    return this->hour;
}

void DateTime::setHour(int hour) {
    if (hour >= 0 && hour < 24)
        this->hour = hour;
}

int DateTime::getMinutes() const {
    return this->minutes;
}

void DateTime::setMinutes(int minutes) {
    if (minutes >= 0 && minutes < 60)
        this->minutes = minutes;
}

void DateTime::serialize(std::ostream &out) const {
    out.write((char *)this, sizeof(*this));
}

void DateTime::deserialize(std::istream &in) {
    in.read((char *)this, sizeof(*this));
}

DateTime DateTime::operator+(const DateTime &o) const {
    DateTime ans;
    ans.year = this->year + o.year;
    ans.month = this->month + o.month;
    ans.day = this->day + o.day;
    ans.hour = this->hour + o.hour;
    ans.minutes = this->minutes + o.minutes;

    ans.hour += ans.minutes / 60;
    ans.minutes %= 60;

    ans.day += ans.hour / 24;
    ans.hour %= 24;

    ans.month += (ans.day - 1) / 31;
    ans.day = (ans.day - 1) % 31 + 1;

    ans.year += (ans.month - 1) / 12;
    ans.month = (ans.month - 1) % 12 + 1;

    return ans;
}

void DateTime::operator+=(const DateTime &o) {
    this->year += o.year;
    this->month += o.month;
    this->day += o.day;
    this->hour += o.hour;
    this->minutes += o.minutes;

    this->hour += this->minutes / 60;
    this->minutes %= 60;

    this->day += this->hour / 24;
    this->hour %= 24;

    this->month += (this->day - 1) / 31;
    this->day = (this->day - 1) % 31 + 1;

    this->year += (this->month - 1) / 12;
    this->month = (this->month - 1) % 12 + 1;
}

std::istream &operator>>(std::istream &in, DateTime &d) {
    char c;
    in >> d.day >> c;
    in >> d.month >> c;
    in >> d.year;
    in >> d.hour >> c;
    in >> d.minutes;

    return in;
}

std::ostream &operator<<(std::ostream &out, const DateTime &d) {
    out << std::setfill('0')
        << std::setw(2) << d.day << "."
        << std::setw(2) << d.month << "."
        << std::setw(4) << d.year << " "
        << std::setw(2) << d.hour << ":"
        << std::setw(2) << d.minutes;

    return out;
}