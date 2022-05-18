#pragma once
#include "Animal.h"
class Pet :public Animal {
public:
	Pet();
	Pet(const char* name, unsigned age, const char* owner, unsigned phone);
	Pet(const Pet& other);
	Pet& operator=(const Pet& other);
	~Pet();

	void print() const;
	void changeOwner(const char* name, unsigned phone);

private:
	char* owner;
	unsigned phone;
};