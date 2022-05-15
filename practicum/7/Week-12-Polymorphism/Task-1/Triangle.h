#pragma once
#include "Shape.h"
#include <math.h>
class Triangle: public Shape {
public:
	Triangle(double x, double y, const char* color, 
		double a, double b, double c,
		double angle_ab, double angle_bc, double angle_ca)
		:Shape(x, y, color),
		a(a), b(b), c(c),
		angle_ab(angle_ab), angle_bc(angle_bc), angle_ca(angle_ca) 
	{}

	virtual void print() const override {
		std::cout << "Triangle\n";
		Shape::print();
		std::cout << "a: " << a << ", b: " << b << ", c: " << c << "\n";
		std::cout << "angle_ab: " << angle_ab << ", angle_bc: " << angle_bc << ", angle_ca: " << angle_ca << "\n\n";
	}

	virtual double perimeter() const override {
		return a + b + c;
	}

	virtual double surface() const override {
		return 1 / 2 * a * b * sin(angle_ab);
	}

private:
	double a;
	double b;
	double c;
	double angle_ab;
	double angle_bc;
	double angle_ca;
};