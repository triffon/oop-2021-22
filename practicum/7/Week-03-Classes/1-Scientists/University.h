#pragma once
#include "Scientist.h"

class University {
public:
	University(int capacity)
	{
		scientists = new Scientist * [capacity];
		size = 0;
		this->capacity = capacity;
	}

	~University() {
		for (int i = 0; i < size; ++i)
			scientists[i];

		delete[] scientists;
	}

	void hire(const char* name, Title title, int salary, int income) {
		if (size < capacity) {
			scientists[size] = new Scientist(name, title, salary, income);

			size++;
		}
	}

	void fire(const char* name) {
		for (int i = 0; i < size; i++) {
			if (strcmp(scientists[i]->getName(), name) == 0) {
				delete scientists[i];
				shift(i);
			}
		}
	}

	void giveRaise(const char* name) {
		for (int i = 0; i < size; i++) {
			if (strcmp(scientists[i]->getName(), name) == 0) {
				scientists[i]->raise();
			}
		}
	}

	void fire(Title title) {
		for (int i = 0; i < size; i++) {
			if (scientists[i]->getTitle() == title) {
				delete scientists[i];
				shift(i);
			}
		}
	}

	int getProfit() const {
		int income = 0;
		int expenses = 0;

		for (int i = 0; i < size; ++i) {
			income += scientists[i]->getIncome() * 30;
			expenses += scientists[i]->getSalary();
		}

		return income - expenses;
	}

	void print() const {
		std::cout << getProfit() << ": \n";

		for (int i = 0; i < size; ++i)
			scientists[i]->print();
	}
private:
	//We're using Scientists** because we still don't know about
	// copy ctors and operator= and this is a way to avoid using them
	Scientist** scientists;
	int size;
	int capacity;

	void shift(int pos) {
		for (int i = pos; i < size - 1; ++i) {
			scientists[i] = scientists[i + 1];
		}
		size--;
	}
};