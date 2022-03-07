#include <iostream>

// 4. създайте структура distance, която има два члена - инчове и футове. напишете функция, 
//    която я принтира във формата <футове>’<инчове>’’.

// 5. напишете функция, която събира две дистанции. забележка: 1 фут = 12 инча.

const int feet_to_inch = 12;

struct distance
{
	float feet;
	float inch;
};

void init(distance& dist)
{
	float inch;
	float feet;

	std::cin >> feet >> inch;

	dist.feet = feet;

	if (inch >= feet_to_inch)
	{
		dist.feet += floor(inch / feet_to_inch);
		dist.inch = inch - floor(inch / feet_to_inch) * feet_to_inch;
	}
	else
	{
		dist.inch = inch;
	}
}

distance sumdistance(distance& rhs, distance& lhs)
{
	distance result;

	if (lhs.inch + rhs.inch >= feet_to_inch)
	{
		result.feet = rhs.feet + lhs.feet + 1;
		result.inch = rhs.inch + lhs.inch - feet_to_inch;
	}
	else
	{
		result.feet = rhs.feet + lhs.feet;
		result.inch = rhs.inch + lhs.inch;
	}

	return result;
}

void printdistance(distance& dist)
{
	std::cout << dist.feet << '\'' << dist.inch << '"';
}

int main()
{
	distance dist1, dist2;

	init(dist1);
	init(dist2);

	distance result = sumdistance(dist1, dist2);

	printdistance(result);

	return 0;
}