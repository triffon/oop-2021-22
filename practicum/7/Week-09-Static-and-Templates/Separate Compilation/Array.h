#ifndef __ARRAY__HEADER__INCLUDED__
#define __ARRAY__HEADER__INCLUDED__
#include <iostream>

template <typename T>
class Array {
public:
	Array();
	~Array();

	void add(const T& element);
	void print();

private:
	T* arr;
	size_t size;
};

#include "Array.inc"
#endif

// Малко повече обяснение за проблемите
//https://stackoverflow.com/questions/9191210/templates-and-separate-compilation

