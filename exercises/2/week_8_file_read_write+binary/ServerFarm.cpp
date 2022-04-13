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

void ServerFarm::resize()
{
	capacity *= 2;
	WebServer* newFarm = new WebServer[capacity];
	for (int i = 0; i < size;i++)
	{
		newFarm[i] = farm[i];
	}
	delete[] farm;
	farm = newFarm;
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
	if (size == capacity)
	{
		resize();
	}
	farm[size++] = newServer;

	return *this;
}

void ServerFarm::print() const
{
	for (int i = 0; i < size; i++)
	{
		farm[i].print();
	}
}

ServerFarm& ServerFarm::operator-=(int* address)
{
	return *this;
}

ServerFarm& ServerFarm::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size;j++)
		{
			if (farm[i] < farm[j])
			{
				std::swap(farm[i], farm[j]);
			}
		}
	}
	return *this;
}

void ServerFarm::save(const char* fileName)
{
	std::ofstream out;
	out.open(fileName);
	if (out)
	{
		for (int i = 0; i < size;i++)
		{
			farm[i].save(out);
		}
	}
	out.close();
}

void ServerFarm::read(const char* fileName)
{
	std::ifstream in;
	in.open(fileName);
	if (in)
	{
		int count = 0;
		char c = ' ';
		while (!in.eof())
		{
			in.get(c);
			if (c == '\n')
			{
				count++;
			}
		}
		in.clear();
		in.seekg(0, std::ios::beg);
		count--;
		destroy();
		name = new char[2];
		name[0] = 'a';
		name[1] = '\0';
		capacity = count;
		size = count;
		farm = new WebServer[count];
		for (int i = 0; i < count;i++)
		{
			farm[i].read(in);
		}
	}
	in.close();
}

void ServerFarm::saveBin(const char* fileName)
{
	std::ofstream out;
	out.open(fileName, std::ios::binary);
	if (out)
	{
		out.write((const char*)&size, sizeof(int));
		for (int i = 0; i < size;i++)
		{
			farm[i].saveBin(out);
		}
	}
	out.close();
}

void ServerFarm::readBin(const char* fileName)
{
	std::ifstream in;
	in.open(fileName, std::ios::binary);
	if (in)
	{
		destroy();
		name = new char[2];
		name[0] = 'a';
		name[1] = '\0';
		in.read((char*)&size, sizeof(int));
		capacity = size;
		farm = new WebServer[size];
		for (int i = 0; i < size;i++)
		{
			farm[i].readBin(in);
		}
	}
	in.close();
}
