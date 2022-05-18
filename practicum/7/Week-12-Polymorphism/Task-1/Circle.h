#pragma once
#include "Shape.h"
class Circle: public Shape {
public:
	Circle(double x, double y, const char* color, double diameter)
		:Shape(x, y, color),
		diameter(diameter) {}

	virtual void print() const  override {
		std::cout << "Circle\n";
		Shape::print();
		std::cout << "d: " << diameter << "\n\n";
	}

	virtual double perimeter() const override {
		return acos(-1) * diameter;
	}

	virtual double surface() const override {
		return cos(-1) * diameter * diameter / 4;
	}

private:
	double diameter;
};