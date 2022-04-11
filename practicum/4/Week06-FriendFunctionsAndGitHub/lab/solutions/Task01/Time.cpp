#include <iostream>

#include "Time.h"

#include <cassert>

Time::Time()
{
	this->hour = 0;
	this->minutes = 0;
}

Time::Time(const unsigned hours, const unsigned minutes)
{
	assert(hours < 24);
	assert(minutes < 60);

	this->type = Type::TWENTY_FOUR;
	
	this->hour = hours;
	this->minutes = minutes;
}

Time::Time(const unsigned hours, const unsigned minutes, const bool isAm)
{
	assert(hours <= 12);
	assert(minutes < 60);

	this->type = Type::TWELVE;
	
	this->hour = hours;
	this->minutes = minutes;
	this->isAm = isAm;
}

Time Time::operator + (const Time& other) const
{
	Time result = *this;

	result.minutes = this->minutes + other.minutes;
	if (result.minutes > 60)
	{
		result.minutes = result.minutes - 60;
		result.hour++;
	}

	result.hour += other.hour;
	if (result.type == Type::TWELVE && result.hour > 12)
	{
		result.hour -= 12;

		result.isAm = !result.isAm;
	}
	else if (result.type == Type::TWENTY_FOUR && result.hour >= 24)
	{
		result.hour -= 24;
		result.isAm = !result.isAm;
	}

	return result;
}

Time Time:: operator + (const unsigned int hours) const
{
	Time temp(hours, 0);

	return  *this + temp;
}


Time operator + (const unsigned int hours, const Time& second)
{
	return second + hours;
}

bool Time:: operator > (const Time& other) const
{
	return this->hour > other.hour ||
		(this->hour == other.hour && this->minutes > other.minutes);
}

std::ostream& operator << (std::ostream& out, const Time& time)
{
	out << time.hour << ":" << time.minutes << std::endl;

	return out;
}