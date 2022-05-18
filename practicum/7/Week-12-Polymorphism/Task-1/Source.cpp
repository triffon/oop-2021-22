#include "ShapeContainer.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Triangle.h"
#include "Circle.h"

int main() {
	ShapeContainer container;

	Rectangle r(10.5, 1.2, "blue", 10, 2);
	Triangle t(1, 1.1, "green", 2, 3, 4, 2, 1, 1);
	Circle c(1, 2, "red", 10);
	Rhombus rh(4.3, 5.5, "orange", 1, 20);

	container.addShape(&r);
	container.addShape(&t);
	container.addShape(&c);
	container.addShape(&rh);

	container.print();
	container.printPerimeters();
	container.printSurfaces();
}