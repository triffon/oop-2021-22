#pragma once
#include "Shape.h"
class Rhombus : public Shape {
public:
	Rhombus(double x, double y, const char* color, double a, double angle)
		:Shape(x, y, color),
		a(a), angle(angle) {}

	virtual void print() const override {
		std::cout << "Rhombus\n";
		Shape::print();
		std::cout << "a: " << a << ", angle: " << angle << "\n\n";
	}

	virtual double perimeter() const override {
		return 4 * a;
	}

	virtual double surface() const override {
		return a * a * sin(angle);
	}

private:
	double a;
	double angle;
};