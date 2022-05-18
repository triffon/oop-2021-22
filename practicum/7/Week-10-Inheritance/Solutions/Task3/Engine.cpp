#include "Engine.h"

Engine::Engine(const char* manu, const char* desc, unsigned short hp)
	: CarPart(manu, desc), horsePower(hp)
{
}

std::ostream& operator<<(std::ostream& os, const Engine& obj)
{
	os << (const CarPart&)obj;
	os << obj.horsePower << '\n';
}
