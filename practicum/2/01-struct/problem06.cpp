#include <iostream>

// 6. Създайте структура TimePeriod, която има 3 члена - часове, минути, секунди.
// Напишете функция, която принтира времеви период във формата hh:mm:ss.
// Напишете функция, която смята разликата между два времеви периода.

// 04:40:23 - 02:50:45 = 01:49:38

const unsigned HOURS_TO_SECONDS = 3600;
const unsigned MINUTES_TO_SECONDS = 60;

struct TimePeriod
{
	unsigned hours;
	unsigned minutes;
	unsigned seconds;
};

void print(TimePeriod& time)
{
	std::cout << time.hours << ':' << time.minutes << ':' << time.seconds << '\n';
}

unsigned TimePeriodToSeconds(TimePeriod& time)
{
	return time.hours * HOURS_TO_SECONDS + time.minutes * MINUTES_TO_SECONDS + time.seconds;
}

TimePeriod SecondsToTimePeriod(unsigned seconds)
{
	TimePeriod result;

	result.hours = seconds / HOURS_TO_SECONDS;
	result.minutes = (seconds % HOURS_TO_SECONDS) / MINUTES_TO_SECONDS;
	result.seconds = seconds % MINUTES_TO_SECONDS;

	return result;
}

TimePeriod sumTimePeriods(TimePeriod& rhs, TimePeriod& lhs)
{
	TimePeriod result = SecondsToTimePeriod(TimePeriodToSeconds(rhs) + TimePeriodToSeconds(lhs));

	return result;
}

TimePeriod differenceTimePeriods(TimePeriod& rhs, TimePeriod& lhs)
{
	TimePeriod result;

	unsigned rhsSeconds = TimePeriodToSeconds(rhs);
	unsigned lhsSeconds = TimePeriodToSeconds(lhs);

	if (lhsSeconds > rhsSeconds)
		result = SecondsToTimePeriod(lhsSeconds - rhsSeconds);
	else
		result = SecondsToTimePeriod(rhsSeconds - lhsSeconds);

	return result;
}

int main()
{
	TimePeriod time1 = {4, 40, 23};
	TimePeriod time2 = { 2, 50, 45 };
	
	TimePeriod result = differenceTimePeriods(time1, time2);

	print(result);

	return 0;
}