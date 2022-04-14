#pragma once

#include <iostream>

enum class Type
{
	TWENTY_FOUR,
	TWELVE
};

class Time
{
	unsigned hour;
	unsigned minutes;
	enum Type type;
	bool isAm;

public:
	Time();
	Time(const unsigned hours, const unsigned minutes);
	Time(const unsigned hours, const unsigned minutes, const bool isAm);
	
	Time operator + (const Time& other) const;
	Time operator + (const unsigned int hours) const;
    friend Time operator + (const unsigned int hours, const Time& second);

	bool operator > (const Time& other) const;

	friend std::ostream& operator << (std::ostream& out, const Time& time);
};