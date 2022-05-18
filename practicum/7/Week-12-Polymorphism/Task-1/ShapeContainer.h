#pragma once
#include "Shape.h"
class ShapeContainer {
public:
	ShapeContainer() {
		arr = new Shape* [10];
		size = 0;
	}
	
	//copy
	//operator=

	~ShapeContainer() {
		delete[] arr;
	}

	void addShape(Shape* shape) {
		if (size >= 10) return;
		
		arr[size] = shape;
		size++;
	}

	void print() const {
		for (size_t i = 0; i < size; ++i)
			arr[i]->print();
	}

	void printPerimeters() const {
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr[i]->perimeter() << " ";
		}
		std::cout << "\n\n";
	}

	void printSurfaces() const {
		for (size_t i = 0; i < size; ++i) {
			std::cout << arr[i]->surface() << " ";
		}
		std::cout << "\n\n";
	}

private:
	Shape** arr;
	size_t size;
};