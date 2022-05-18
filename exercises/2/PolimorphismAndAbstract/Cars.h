#pragma once
#include <iostream>

class Car {
private:
	char* model;
	int horsePower;
public:
	Car();
	Car(const Car& other);
	Car& operator =(const Car& other);
	virtual ~Car();
	virtual void print() const = 0;
	virtual double getRaiting() const = 0;
	int getHorsePower() const {
		return horsePower;
	}
	virtual Car* clone() const = 0;
};

class SportCar : public Car {
private:
	int power;
public:
	void print() const override {
		std::cout << "Sport Car ";
	}
	double getRaiting() const override {
		return power * getHorsePower() / 10;
	}
	SportCar* clone() const {
		return new SportCar(*this);
	}
};

class LuxuryCar : public Car {
private:
	int extrasCount;
public:
	void print() const override {
		std::cout << "Luxury Car ";
	}
	double getRaiting() const override {
		return extrasCount + getHorsePower() / 7;
	}
	LuxuryCar* clone() const {
		return new LuxuryCar(*this);
	}
};