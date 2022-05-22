#pragma once
#include "ClothingItem.h"

class Dress : public ClothingItem {
public:
	Dress(const String& color, const String& size, size_t price, size_t length)
		: ClothingItem(color, size, price), length(length)
	{}

	virtual Type getType() const {
		return Type::DRESS;
	}

	virtual void print(std::ostream& out) const {
		ClothingItem::print(out);
		out << length << "\n";
	}

	virtual ClothingItem* clone() {
		return new Dress(*this);
	}

private:
	size_t length;
};