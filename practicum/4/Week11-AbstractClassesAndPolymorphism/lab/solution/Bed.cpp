#include "Bed.h"

Bed::Bed(const double height, const double width, const double length, const int quantity)
	: Furniture(height, width, length, quantity) {
	m_price = calculatePrice();
}

const std::string Bed::getInfo() const {
	std::string result = Furniture::getInfo();

	result.replace(0, 9, "Bed");

	return result;
}

const std::string Bed::getStrComparator() const {
	return "Bed " + Furniture::getStrComparator();
}

Furniture* Bed::clone() {
	Furniture* bed = new Bed(m_height, m_width, m_length, m_quantity);

	bed->setID(m_id);
	--Furniture::COUNTER;

	return bed;
}

double Bed::calculatePrice() const {
	return m_length * m_height * PRICE_MULTIPLIER;
}
