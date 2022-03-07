#include "Beer.h"

Beer::Beer()
{
	volume = 0;
	brand[0] = '\0';
}

Beer::Beer(const char* newBrand, unsigned newVolume)
{
	volume = newVolume;
	strcpy_s(brand, newBrand);
}

void Beer::setVolume(unsigned newVolume)
{
	volume = newVolume;
}

void Beer::setBrand(const char* newBrand)
{
	strcpy_s(brand, newBrand);
}

unsigned Beer::getVolume()const
{
	return volume;
}

const char* Beer::getBrand()const
{
	return brand;
}

void Beer::print()const
{
	std::cout << "Beer brand is " << brand << ";\nBeer volume is " << volume << "\n";
}