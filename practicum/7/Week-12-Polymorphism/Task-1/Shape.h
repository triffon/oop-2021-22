#pragma once
#include <iostream>
#include <cstring>
class Shape {
public:
	Shape(double x, double y, const char* color) :x(x), y(y) {
		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);
	}

	Shape(const Shape& other) {
		copy(other.x, other.y, other.color);
	}

	Shape& operator=(const Shape& other) {
		if (this != &other) {
			delete[] color;
			copy(other.x, other.y, other.color);
		}

		return *this;
	}

	virtual ~Shape() {
		delete[] color;
	}

	virtual void print() const = 0{
		std::cout << "x: " << x << ", y: " << y << ", " << color << "\n";
	}

	virtual double perimeter() const = 0;
	virtual double surface() const = 0;

private:
	void copy(double x, double y, const char* color) {
		this->x = x;
		this->y = y;

		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);
	}

	double x;
	double y;
	char* color;
};