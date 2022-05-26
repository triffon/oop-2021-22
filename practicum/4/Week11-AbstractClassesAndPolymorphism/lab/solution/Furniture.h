#ifndef FURNITURE_H
#define FURNITURE_H

#include <iostream>
#include <string>

#include "Utility.h"

class Furniture {
public:
	static int COUNTER;

public:
	void setID(const int newID);

	int getID() const;

	int getQuantity() const;

	void setQuantity(const int quantity);

	double getPrice() const;

	virtual void read(std::istream& in = std::cin);

	virtual const std::string getInfo() const;

	virtual const std::string getStrComparator() const;

	virtual Furniture* clone() = 0;

protected:
	virtual double calculatePrice() const = 0;

protected:
	Furniture(const double height = 0, const double width = 0, const double length = 0, const int quantity = 0);

protected:
	int m_id;
	double m_height;
	double m_width;
	double m_length;
	int m_quantity;
	double m_price;
};

#endif // !FURNITURE_H
