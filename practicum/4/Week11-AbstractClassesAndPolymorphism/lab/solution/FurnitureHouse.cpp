#include "FurnitureHouse.h"

FurnitureHouse::FurnitureHouse() : m_data(nullptr), m_size(0), m_capacity(0) {
	allocData(2);
}

FurnitureHouse::FurnitureHouse(const FurnitureHouse& other)
				 : m_data(nullptr), m_size(0), m_capacity(0) {
	copy(other);
}

FurnitureHouse::~FurnitureHouse() {
	deleteData();
}

size_t FurnitureHouse::size() const {
	return m_size;
}

Furniture* FurnitureHouse::getFurnitureAtID(const int id) const {
	for (size_t index = 0; index < m_size; ++index)
		if (m_data[index]->getID() == id)
			return m_data[index];

	return nullptr;
}

void FurnitureHouse::print() const {
	for (size_t index = 0; index < m_size; ++index)
		std::cout << m_data[index]->getInfo() << std::endl;
}

Furniture* FurnitureHouse::operator[](const int index) {
	return getFurnitureAtIndex(index);
}

const Furniture* FurnitureHouse::operator[](const int index) const {
	return getFurnitureAtIndex(index);
}

FurnitureHouse& FurnitureHouse::operator+=(Furniture* furniture) {
	if (m_size >= m_capacity)
		allocData(m_capacity * 2);

	m_data[m_size++] = furniture;

	return *this;
}

FurnitureHouse& FurnitureHouse::operator-=(Furniture* furniture) {
	if (getFurnitureAtID(furniture->getID()) == nullptr) return *this;

	furniture->setQuantity(furniture->getQuantity() - 1);

	if (furniture->getQuantity() == 0) {
		std::swap(furniture, m_data[--m_size]);
	}

	return *this;
}

FurnitureHouse& FurnitureHouse::operator=(const FurnitureHouse& other) {
	if (this != &other) copy(other);

	return *this;
}

void FurnitureHouse::deleteData() {
	for (size_t index = 0; index < m_size; ++index) {
		delete m_data[index];
		m_data[index] = nullptr;
	}

	delete[] m_data;
	m_data = nullptr;
}

void FurnitureHouse::allocData(size_t newCapacity) {
	if (m_size >= newCapacity) newCapacity = m_size + 1;

	Furniture** blockOfMem = new Furniture*[newCapacity]{nullptr, };

	for (size_t index = 0; index < m_size; ++index)
		blockOfMem[index] = m_data[index]->clone();

	deleteData();
	m_data = blockOfMem;
	m_capacity = newCapacity;
}

void FurnitureHouse::copy(const FurnitureHouse& other) {
	deleteData();
	m_data = new Furniture*[other.m_capacity]{ nullptr, };

	for (size_t index = 0; index < other.m_size; ++index)
		m_data[index] = other.m_data[index]->clone();

	m_size = other.m_size;
}

Furniture* FurnitureHouse::getFurnitureAtIndex(const int index) const {
	if (index < 0 || index >= m_size)
		throw "Index out of bounds!";

	return m_data[index];
}
