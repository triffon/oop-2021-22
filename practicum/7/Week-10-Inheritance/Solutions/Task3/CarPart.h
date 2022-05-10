#pragma once
#include <cstring>
#include <iostream>
class CarPart
{
	static size_t nextId;
	size_t id;
	char* manufacturer;
	char* description;
public:
	friend std::ostream& operator<<(std::ostream& os, const CarPart& obj);
	void setManufacturer(const char* manu);
	void setDescription(const char* desc);

	CarPart();
	CarPart(const char* manu, const char* desc);
	CarPart(const CarPart& src);
	CarPart& operator=(const CarPart& rhs);
	~CarPart();
};

