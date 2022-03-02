#include "Rational.h"
#include <iostream>

void Rational::print() const
{
	std::cout << this->num << '/' << dem;
}

void Rational::setNum(int _num)
{
	this->num = _num;
}

void Rational::setDem(int dem)
{
	if (dem == 0)
	{
		std::cout << "0 is not valid";
		return;
	}
	this->dem = dem;
}

int Rational::getNum() const
{
	return num;
}

int Rational::getDem() const 
{
	return dem;
}

void Rational::read()
{
	int n;
	std::cout << "Enter num:\n";
	std::cin >> n;
	this->setNum(n);
	std::cout << "Enter dem\n";
	std::cin >> n;
	this->setDem(n);
}
