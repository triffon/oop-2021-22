#pragma once


class Polynome {
private:
	int* coef;
	int degree;
	void copy(const Polynome& other);
	void destroy();
public:
	Polynome();
	Polynome(int degree);
	Polynome(const Polynome& other);
	Polynome& operator=(const Polynome& other);
	Polynome& operator *(int scalar);

	~Polynome();

	void print() const;

};