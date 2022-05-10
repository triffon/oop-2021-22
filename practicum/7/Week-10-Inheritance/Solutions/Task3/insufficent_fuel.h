#pragma once
#include <stdexcept>
#include <iostream>
class insufficent_fuel : public std::logic_error
{
public:
	insufficent_fuel(const char* msg) : std::logic_error(msg)
	{}
};

int main()
{
	try {
		//...
	}
	catch (insufficent_fuel& e) {
		std::cerr << e.what();
	}
}

