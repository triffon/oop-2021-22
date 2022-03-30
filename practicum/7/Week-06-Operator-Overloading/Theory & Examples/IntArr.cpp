#include "IntArr.h"
#include <iostream>
#include <stdexcept>

//
// Big 4
//
IntArr::IntArr()
	:size(0), 
	capacity(2),
	arr(new int[capacity])
{}

IntArr::IntArr(const IntArr& other) {
	copy(other);
}

IntArr& IntArr::operator=(const IntArr& other) {
	if (this != &other) {
		clear();
		copy(other);
	}

	return *this;
}

IntArr::~IntArr() {
	clear();
}

//
// Operators
//

//Връща дали е празен масива
bool IntArr::operator!() const {
	return size == 0;
}

//Ще добавим ново число в масива
IntArr& IntArr::operator+=(int n) {
	if (size == capacity)
		resize();

	arr[size] = n;
	size++;

	return *this;
} 

//Ще слеем два масива
IntArr& IntArr::operator+=(const IntArr& rhs) {
	for (size_t i = 0; i < rhs.size; ++i)
		*this += rhs.arr[i];

	return *this;
} 

//Ще умножим по n всички числа в масива
IntArr& IntArr::operator*=(int n) {
	for (size_t i = 0; i < size; ++i)
		arr[i] *= n;

	return *this;
}

//Префиксно ++arr
IntArr& IntArr::operator++() {
	for (size_t i = 0; i < size; ++i)
		++arr[i];

	return *this;
}

//Постфиксно arr++
IntArr& IntArr::operator++(int n) {
	IntArr old = *this;
	operator++();
	return old;
}

//Връщаме елемента на index
int& IntArr::operator[](size_t index) {
	if (index >= size)
		throw std::out_of_range("Index is out of range");

	return arr[index];
}

//Дали всички елементи са еднакви
bool operator==(const IntArr& lhs, const IntArr& rhs) {
	if (lhs.size != rhs.size)
		return false;

	for (size_t i = 0; i < lhs.size; ++i)
		if (lhs.arr[i] != rhs.arr[i])
			return false;

	return true;
}

//Дали има различен елемент
bool operator!=(const IntArr& lhs, const IntArr& rhs) {
	return !(lhs == rhs);
}

//Дали първия е с по-големи елементи от втория
bool operator>(const IntArr& lhs, const IntArr& rhs) {
	if (lhs.size < rhs.size)
		return false;

	for (size_t i = 0; i < rhs.size; ++i)
		if (lhs.arr[i] <= rhs.arr[i])
			return false;

	return true;
}

//Дали първия е с по-големи или равни елементи
bool operator>=(const IntArr& lhs, const IntArr& rhs) {
	return lhs == rhs || lhs > rhs;
}

//
// Външни, но не са приятели, защото в тях не използваме нищо от класа, 
// а викаме вече дефинирани оператори
// 

//IntArr array = anotherArr + 5;
IntArr operator+(const IntArr& lhs, int rhs) {
	IntArr temp(lhs); //Правим копие
	temp += rhs; //за да не променим подадения масив
	return temp;
}

//IntArr array = anotherArr + otherAnotherArr;
IntArr operator+(const IntArr& lhs, const IntArr& rhs) {
	IntArr temp(lhs);
	temp += rhs;
	return temp;
}

//IntArr array = anotherArr * 2;
IntArr operator*(const IntArr& lhs, int rhs) {
	IntArr temp(lhs);
	temp *= rhs;
	return temp;
}

//Принтира във вида [ 1 2 3 4 ]
void IntArr::print() const {
	std::cout << "[ ";

	for (size_t i = 0; i < size; ++i)
		std::cout << arr[i] << " ";

	std::cout << "]\n";
}

//
// Private methods:
//

//Копира стойностите от друг IntArr
void IntArr::copy(const IntArr& other) {
	size = other.size;
	capacity = other.capacity;

	arr = new int[capacity];
	for (size_t i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

//Изчиства паметта
void IntArr::clear() {
	delete[] arr;
	arr = nullptr;
}

//Преоразмеряваме масива
void IntArr::resize() {
	int* temp = new int[2 * capacity];

	for (size_t i = 0; i < size; ++i)
		temp[i] = arr[i];

	delete[] arr;
	arr = temp;
	capacity *= 2;
}