#include "date.h"
#include <cassert>
#include <iostream>

const unsigned int MONTH_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(unsigned int year)
{
    return (year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0));
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    assert(month > 0 && month <= 12);
    assert(day > 0 && day <= MONTH_DAYS[month - 1] + (month == 2 && isLeap(year)));

    m_day = day;
    m_month = month;
    m_year = year;
}

unsigned int Date::day() const
{
    return m_day;
}

unsigned int Date::month() const
{
    return m_month;
}

unsigned int Date::year() const
{
    return m_year;
}

bool Date::operator==(const Date &rhs) const
{
    return m_year == rhs.m_year && m_month == rhs.m_month && m_day == rhs.m_day;
}

bool Date::operator<(const Date &rhs) const
{
    return m_year < rhs.m_year || m_month < rhs.m_month || m_day < rhs.m_day;
}

void Date::printNumberWithLeadingZero(unsigned int number) const
{
    if (number < 10)
    {
        std::cout << "0";
    }
    std::cout << number;
}

void Date::print() const
{
    printNumberWithLeadingZero(this->day());
    std::cout << ".";
    printNumberWithLeadingZero(this->month());
    std::cout << ".";
    printNumberWithLeadingZero(this->year());
}