#include "Table.h"

Table::Table(const double height, const double width, const double length, const int quantity, const TableType type)
	: Furniture(height, width, length, quantity), m_type(type) {
	m_price = calculatePrice();
}

void Table::read(std::istream& in) {
	Furniture::read(in);
	m_price = calculatePrice();

	std::cout << "Enter Table Type (living room | kitchen): ";

	std::string tableType;

	do {
		std::getline(in, tableType);

		tableType = Utility::toLowerStr(tableType);
	} while (tableType != "living room" && tableType != "kitchen");

	m_type = (tableType == "living room" ? TableType::LIVING_ROOM : TableType::KITCHEN);
}

const std::string Table::getInfo() const {
	std::string result = Furniture::getInfo();

	result.replace(0, 9, "Table");

	std::string type = (m_type == TableType::LIVING_ROOM ? "Living Room" : "Kitchen");

	result += "Type: " + type + '\n';

	return result;
}

const std::string Table::getStrComparator() const {
	return "Table " +
		Furniture::getStrComparator() + " " +
		std::to_string(m_type == TableType::LIVING_ROOM ? 0 : 1);
}

Furniture* Table::clone() {
	Furniture* table = new Table(m_height, m_width, m_length, m_quantity, m_type);

	table->setID(m_id);
	--Furniture::COUNTER;

	return table;
}

double Table::calculatePrice() const {
	return m_width * m_length * PRICE_MULTIPLIER;
}
