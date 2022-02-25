#pragma once
#include <iostream>

void test();

struct Cup {
	int capacity;
	char material[32];
};

struct Person {
	int age;
	int money;
	char name[50];
	long long pid; // char pid[11]
	bool gender;
	bool isActive;
	Cup myCup;
	void print() {
		std::cout << "Person is " << age << " years old and is " << (gender ? "Female" : "Male") << " and has cup capacity of " << myCup.capacity << "ml. and has " << money << " in bank account" << '\n';
	}
	void init() {
		char _gender;
		std::cin >> age;
		std::cout << "Enter gender: m for male, f for female\n";
		std::cin >> _gender;
		gender = _gender != 'm';
		std::cin >> myCup.capacity;
		std::cin >> money;
	}
	void sleep();
	void recieveMoney(int addedMoney) {
		money += addedMoney;
	}
};

void recievePerson(Person p) {
	p.money = 0;
}


void test() {
	Person person;
	person.init();
	Person person2;
	//person2.init();

	person.print();
	//....
	person.recieveMoney(50);
	recievePerson(person);

	person.print();
	//person2.print();
}