#pragma once
#include "CarPart.h"
class Engine : public CarPart
{
	unsigned short horsePower;
	friend std::ostream& operator<<(std::ostream& os, const Engine& obj);
public:
	Engine(const char* manu, const char* desc, unsigned short hp = 0);
};

