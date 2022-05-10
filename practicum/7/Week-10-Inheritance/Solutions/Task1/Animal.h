#pragma once
class Animal {
public:
	Animal();
	Animal(const char* name, unsigned age);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	~Animal();


	void print() const;
	void setName(const char* name);

private:
	char* name;
	unsigned age;
};