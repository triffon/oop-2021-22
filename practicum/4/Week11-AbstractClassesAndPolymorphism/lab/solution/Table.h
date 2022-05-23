#ifndef TABLE_H
#define TABLE_H

#include "Furniture.h"
#include "TableType.h"

class Table : public Furniture {
public:
	Table(const double height = 0, const double width = 0, const double length = 0, const int quantity = 0, const TableType type = TableType::LIVING_ROOM);

	void read(std::istream& in = std::cin) override;

	const std::string getInfo() const override;

	const std::string getStrComparator() const override;

	Furniture* clone() override;

protected:
	double calculatePrice() const override;

private:
	const double PRICE_MULTIPLIER = 15;

	TableType m_type;
};

#endif // !TABLE_H
