#include "Chair.h"

Chair::Chair(const double height, const double width, const double length, const int quantity, const ChairType type)
	: Furniture(height, width, length, quantity), m_type(type) {
	m_price = calculatePrice();
}

void Chair::read(std::istream& in) {
	Furniture::read(in);
	m_price = calculatePrice();

	std::cout << "Enter Chair Type (wooden | plastic | metal): ";

	std::string chairType;

	do {
		in >> chairType;

		chairType = Utility::toLowerStr(chairType);
	} while (chairType != "wooden" && chairType != "plastic" && chairType != "metal");

	m_type = (chairType == "wooden" ? ChairType::WOODEN : (chairType == "plastic" ? ChairType::PLASTIC : ChairType::METAL));
}

const std::string Chair::getInfo() const {
	std::string result = Furniture::getInfo();

	result.replace(0, 9, "Chair");

	std::string type = (m_type == ChairType::WOODEN ? "Wooden" : (m_type == ChairType::METAL ? "Metal" : "Plastic"));

	result += "Type: " + type + '\n';

	return result;
}

const std::string Chair::getStrComparator() const {
	return "Chair " +
		Furniture::getStrComparator() + " " +
		std::to_string((m_type == ChairType::WOODEN ? 0 : (m_type == ChairType::METAL ? 1 : 2)));
}

Furniture* Chair::clone() {
	Furniture* chair = new Chair(m_height, m_width, m_length, m_quantity, m_type);

	chair->setID(m_id);
	--Furniture::COUNTER;

	return chair;
}

double Chair::calculatePrice() const {
	return m_height * m_width * PRICE_MULTIPLIER;
}
