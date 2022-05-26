#pragma once
#include "ClothingItem.h"

class Pants : public ClothingItem {
public:
	Pants(const String& color, const String& size, size_t price, size_t length)
		:ClothingItem(color, size, price), length(length) {}

	virtual Type getType() const {
		return Type::PANTS;
	}

	virtual void print(std::ostream& out) const {
		ClothingItem::print(out);
		out << length << "\n";
	}

	virtual ClothingItem* clone() {
		return new Pants(*this);
	}

private:
	size_t length;
};