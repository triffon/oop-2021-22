#pragma once

#include <cstdint>

class Date
{
private:
    std::uint8_t m_day;
    std::uint8_t m_month;
    std::uint16_t m_year;

    void printNumberWithLeadingZero(unsigned int number) const;

public:
    Date(unsigned int day, unsigned int month, unsigned int year);

    unsigned int day() const;
    unsigned int month() const;
    unsigned int year() const;

    bool operator==(const Date& rhs) const;
    bool operator<(const Date& rhs) const;

    void print() const;
};