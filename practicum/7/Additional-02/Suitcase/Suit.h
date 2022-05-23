#pragma once
#include "ClothingItem.h"

class Suit : public ClothingItem {
public:
	Suit(const String& color, const String& size, size_t price)
		:ClothingItem(color, size, price) {}

	virtual Type getType() const {
		return Type::SUIT;
	}

	virtual ClothingItem* clone() {
		return new Suit(*this);
	}
};