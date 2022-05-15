#pragma once
#include "Shape.h"
class Rectangle : public Shape {
public:
	Rectangle(double x, double y, const char* color, double a, double b)
		:Shape(x, y, color), a(a), b(b) {}

	virtual void print() const override {
		std::cout << "Rectangle\n";
		Shape::print();
		std::cout << "a: " << a << ", b: " << b << "\n\n";
	}

	virtual double perimeter() const override {
		return (a + b) * 2;
	}

	virtual double surface() const override {
		return a * b;
	}

private:
	double a;
	double b;
};