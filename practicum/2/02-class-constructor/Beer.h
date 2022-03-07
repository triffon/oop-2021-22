#pragma once
#include <iostream>
#include <cstring>

const int MAX_BRAND_LEN = 128;

class Beer
{
private:
	char brand[MAX_BRAND_LEN];
	unsigned volume;

public:
	Beer();
	Beer(const char* newBrand, unsigned newVolume);

	void setVolume(unsigned newVolume);
	void setBrand(const char* newBrand);

	unsigned getVolume()const;
	const char* getBrand()const;

	void print()const;

};