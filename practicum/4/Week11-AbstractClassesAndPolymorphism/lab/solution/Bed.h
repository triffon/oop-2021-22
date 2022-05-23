#ifndef BED_H
#define BED_H

#include "Furniture.h"

class Bed : public Furniture {
public:
	Bed(const double height = 0, const double width = 0, const double length = 0, const int quantity = 0);

	const std::string getInfo() const override;

	const std::string getStrComparator() const override;

	Furniture* clone() override;

protected:
	double calculatePrice() const override;

private:
	const double PRICE_MULTIPLIER = 22;
};

#endif // !BED_H
