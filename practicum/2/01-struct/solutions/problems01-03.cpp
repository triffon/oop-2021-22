#include <iostream>

// 1. Създайте структура, която да представлява комплексно число.
// 2. Напишете функция, която събира две комплексни числа.
// 3. Напишете функция, която изкарва правилно комплексно число. - 3i + 4



struct ComplexNumber
{
	int real;
	int imaginary;
};

void init(ComplexNumber& number)
{
	int newReal, newImaginary;

	std::cin >> newReal >> newImaginary;

	number.real = newReal;
	number.imaginary = newImaginary;
}

ComplexNumber ComplexSum(ComplexNumber& lhs, ComplexNumber& rhs)
{
	ComplexNumber result;

	result.real = lhs.real + rhs.real;
	result.imaginary = lhs.imaginary + rhs.imaginary;

	return result;
}

void printComplex(ComplexNumber& number)
{
	std::cout << number.imaginary << 'i';

	if (number.real >= 0)
		std::cout << " + " << number.real;
	else
		std::cout << " - " << -number.real;
}

int main()
{
	ComplexNumber compl1 = { 3, -2 };

	printComplex(compl1);

	return 0;
}