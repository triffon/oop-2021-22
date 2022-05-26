#include "Furniture.h"

int Furniture::COUNTER = 0;

Furniture::Furniture(const double height, const double width, const double length, const int quantity)
	: m_id(++COUNTER), m_height(height), m_width(width), m_length(length), m_quantity(quantity) {
}

void Furniture::setID(const int newId) {
	m_id = newId;
}

int Furniture::getID() const {
	return m_id;
}

int Furniture::getQuantity() const {
	return m_quantity;
}

void Furniture::setQuantity(const int quantity) {
	m_quantity = quantity;
}

double Furniture::getPrice() const {
	return m_price;
}

void Furniture::read(std::istream& in) {
	std::cout << "Enter Height: ";
	in >> m_height;

	std::cout << "Enter Lenght: ";
	in >> m_length;

	std::cout << "Enter Width: ";
	in >> m_width;

	std::cout << "Enter Quantity: ";
	in >> m_quantity;
}

const std::string Furniture::getInfo() const {
	std::string result = "";

	result += "Furniture with ID: " + std::to_string(m_id) + "\n";
	result += "Height: " + std::to_string(m_height) + "\n";
	result += "Length: " + std::to_string(m_length) + "\n";
	result += "Width: " + std::to_string(m_width) + "\n";
	result += "Quantity: " + std::to_string(m_quantity) + "\n";
	result += "Price: " + std::to_string(m_price) + "\n";

	return result;
}

const std::string Furniture::getStrComparator() const {
	return std::to_string(m_height) + " " + std::to_string(m_length) + " " + std::to_string(m_width);
}
