#pragma once
#include <iostream>

class Expression {
public:
	virtual double value() const = 0;
	virtual void print() const = 0;
};

class Constant : public Expression {
private:
	double val;
public:
	Constant(double _value) : val(_value) {};
	double value() const override {
		return val;
	}
	void print() const override {
		std::cout << val << " ";
	}
};

class Operation : public Expression {
private:
	char operation;
	Expression** expressions;
	unsigned size;
public:
	Operation(char op, Expression** _exprs, unsigned n) : operation(op), size(n) {
		expressions = new Expression * [size];
		for (unsigned i = 0; i < size;i++)
		{
			expressions[i] = _exprs[i];  // shalow copy
		}
	}
	double value() const override {
		double result = 0.0;
		//homework
		return result;
	}
	void print() const override {
		for (unsigned i = 0; i < size;i++)
		{
			expressions[i]->print();
		}
		std::cout << "Operation: " << operation << '\n';
	}
};

class Input : public Expression {
public:
	double value() const override {
		double readValue;
		std::cout << "\nEnter value: ";
		std::cin >> readValue;
		return readValue;
	}
	void print() const override {
		std::cout << "Input" << " ";
	}
};