#pragma once
#include <iostream>
#include "String.h"
enum class Type {
	DRESS,
	PANTS,
	SUIT
};

class ClothingItem {
public:
	ClothingItem(const String& color, const String& size, size_t price) {
		this->color = color;
		this->size = size;
		this->price = price;
	}

	virtual ~ClothingItem() = default;

	virtual Type getType() const = 0;
	
	virtual String getColor() const {
		return color;
	}
	
	virtual void print(std::ostream& out) const {
		out << color << ", " << size << ", " << price;
	}

	virtual ClothingItem* clone() = 0;

private:
	String color;
	String size;
	size_t price;
};