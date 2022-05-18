#include "CarPart.h"

size_t CarPart::nextId = 0;

CarPart::CarPart() : id(nextId), description(nullptr), manufacturer(nullptr)
{
	nextId++;
	setDescription("Default desc");
	setManufacturer("Default manu");
}

CarPart::CarPart(const char* manu, const char* desc)
	: id(nextId), description(nullptr), manufacturer(nullptr)
{
	nextId++;
	setDescription(desc);
	setManufacturer(manu);
}

CarPart::CarPart(const CarPart& src)
	: id(nextId), description(nullptr), manufacturer(nullptr)
{
	nextId++;
	setDescription(src.description);
	setManufacturer(src.manufacturer);
}

CarPart& CarPart::operator=(const CarPart& rhs)
{
	if (this != &rhs) {
		id = rhs.id;
		setDescription(rhs.description);
		setManufacturer(rhs.manufacturer);
	}
	return *this;
}

CarPart::~CarPart()
{
	delete[] manufacturer;
	delete[] description;
	manufacturer = description = nullptr;
}

void CarPart::setManufacturer(const char* manu)
{
	if (manufacturer) {
		delete[] manufacturer;
	}
	manufacturer = new char[strlen(manu) + 1];
	strncpy(manufacturer, manu, strlen(manu) + 1);
}

void CarPart::setDescription(const char* desc) {
	if (description) {
		delete[] description;
	}
	description = new char[strlen(desc) + 1];
	strncpy(description, desc, strlen(desc) + 1);
}

std::ostream& operator<<(std::ostream& os, const CarPart& obj)
{
	os << "(" << obj.id << ")" << " by " << obj.manufacturer << " - " << obj.description << " - ";
	return os;
}
