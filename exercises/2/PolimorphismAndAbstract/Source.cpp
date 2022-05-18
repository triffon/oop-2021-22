#include <iostream>
#include "Expressions.h"

double maxAll(Expression** arr, int n)
{
	double max = 0.0;
	for (int i = 0; i < n;i++)
	{
		double currrent = arr[i]->value();
		if (currrent > max)
		{
			max = currrent;
		}
	}
	return max;
}

int main() {
	Expression* ptr;
	Expression* ptr2;
	Expression* ptr3;
	Expression* ptr4;
	Expression* ptr5;
	Constant c(5.5);
	Constant a(4.5);
	Constant s(3.5);
	Constant d(7.5);
	Constant f(0.5);
	ptr = &c;
	ptr2 = &a;
	ptr3 = &s;
	ptr4 = &d;
	ptr5 = &f;

	Expression** arr = new Expression * [5];
	arr[0] = ptr;
	arr[1] = ptr2;
	arr[2] = ptr3;
	arr[3] = ptr4;
	arr[4] = ptr5;

	std::cout << maxAll(arr, 5);
	delete[] arr;
	return 0;
}