#include "ServerFarm.h"
#include <cstring>

void ServerFarm::copy(const ServerFarm& other)
{
	size = other.size;
	capacity = other.capacity;
	farm = new WebServer[capacity];
	for (int i = 0; i < size; i++)
	{
		farm[i] = other.farm[i];
	}
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
}

void ServerFarm::destroy()
{
	delete[] name;
	delete[] farm;
}

ServerFarm::ServerFarm()
{
	capacity = 10;
	size = 0;
	farm = new WebServer[capacity];
	name = new char[9];
	strcpy_s(name, 9, "PowerBox");
	//name = new char[2];
	//strcpy_s(name, 2, " ");
}

ServerFarm::ServerFarm(const ServerFarm& other)
{
	copy(other);
}

ServerFarm& ServerFarm::operator=(const ServerFarm& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

ServerFarm::~ServerFarm()
{
	destroy();
}

ServerFarm& ServerFarm::addServer(const WebServer newServer)
{
	farm[size++] = newServer;

	return *this;
}
