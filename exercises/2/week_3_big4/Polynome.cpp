#include "Polynome.h"
#include <iostream>

void Polynome::copy(const Polynome& other)
{
	degree = other.degree;
	coef = new int[degree + 1];
	for (int i = 0; i < degree + 1; i++)
	{
		coef[i] = other.coef[i];
	}
}

void Polynome::destroy()
{
	delete coef;
}

Polynome::Polynome()
{
	degree = 0;
	coef = new int[degree + 1];
	coef[0] = 0;
}

Polynome::Polynome(int degree)
{
	this->degree = degree;
	coef = new int[degree + 1];
	for (int i = 0; i < degree + 1; i++)
	{
		coef[i] = 0;
	}
}

Polynome::Polynome(const Polynome& other)
{
	copy(other);
}

Polynome& Polynome::operator=(const Polynome& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Polynome& Polynome::operator*(int scalar)
{
	std::cout << "audyfbvdsjhbksudybvlsutb";
	return *this;
}

Polynome::~Polynome()
{
	destroy();
}
