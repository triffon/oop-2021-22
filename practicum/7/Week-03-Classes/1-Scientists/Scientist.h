#pragma once
#include <cstring>
#include <iostream>

const int RAISE_MONEY = 100;

enum Title {
	INVALID = -1, 

	ASSISTANT,
	HEAD_ASSISTANT,
	ASSOC_PROF,
	PROF
};

const char* titles[] = { "Assistant", "Head Assistant", "Associate Professor", "Professor" };

class Scientist {
private:
	char* name;
	Title title;
	int salary;
	int income;

public:
	Scientist()
		:name(nullptr), title(INVALID), salary(-1), income(-1) {}

	Scientist(const char* name, Title title, int salary, int income)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);

		this->title = title;
		this->salary = salary;
		this->income = income;
	}

	~Scientist() {
		delete[] name;
	}

	const char* getName() const {
		return name;
	}

	Title getTitle() const {
		return title;
	}

	int getSalary() const {
		return salary;
	}

	int getIncome() const {
		return income;
	}

	void raise() {
		if (title <= PROF) {
			title = (Title)(title + 1);
			salary += RAISE_MONEY;
		}
	}

	void print() const {
		std::cout << name << " - " << titles[title] << "\n";
		std::cout << "Salary: " << salary << ", Daily income for uni: " << income << "\n";
	}
};