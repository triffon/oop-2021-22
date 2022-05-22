#pragma once
#include "String.h"
#include "Person.h"
#include "ClothingItem.h"

class Suitcase {
public:
	Suitcase(const String& color, Person* owner) {
		this->color = color;
		this->owner = owner;

		capacity = 10;
		size = 0;

		clothes = new ClothingItem * [capacity];
	}

	Suitcase(const Suitcase& other) {
		this->color = other.color;
		this->owner = other.owner;

		copyClothes(other.clothes, other.size, other.capacity);
	}

	Suitcase& operator=(const Suitcase& other) {
		if (this != &other) {
			clear();

			this->color = other.color;
			this->owner = other.owner;

			copyClothes(other.clothes, other.size, other.capacity);
		}
		return *this;
	}

	void addClothing(ClothingItem* cloth) {
		if (size >= capacity)
			return;

		clothes[size] = cloth->clone();
		size++;
	}

	ClothingItem* removeClothing(size_t pos) {
		if (pos >= size)
			return nullptr;

		ClothingItem* toReturn = clothes[pos]->clone();

		delete clothes[pos];
		clothes[pos] = clothes[size - 1];
		size--;

		return toReturn;
	}

	bool isInsideType(Type type) {
		for (size_t i = 0; i < size; ++i) {
			if (clothes[i]->getType() == type)
				return true;
		}

		return false;
	}

	bool isInsideColor(const String& color) {
		for (size_t i = 0; i < size; ++i) {
			if (clothes[i]->getColor() == color)
				return true;
		}

		return false;
	}

	bool isInsideTypeColor(Type type, const String& color) {
		for (size_t i = 0; i < size; ++i) {
			if (clothes[i]->getType() == type && clothes[i]->getColor() == color)
				return true;
		}

		return false;
	}

	void print(std::ostream& out) const {
		if (owner)
			out << owner->name << ", " << owner->address << ", " << owner->phone;

		out << color << "\n";
		out << "Contains:\n";

		for (size_t i = 0; i < size; ++i)
			clothes[i]->print(out);
	}

private:
	void copyClothes(ClothingItem** clothes, size_t size, size_t capacity) {
		this->size = size;
		this->capacity = capacity;

		clothes = new ClothingItem * [capacity];
		for (size_t i = 0; i < size; ++i) {
			this->clothes[i] = clothes[i]->clone();
		}
	}

	void clear() {
		for (size_t i = 0; i < size; ++i)
			delete clothes[i];

		delete[] clothes;
	}

	String color;
	Person* owner;

	ClothingItem** clothes;
	size_t size;
	size_t capacity;
};