#pragma once
#include "WebServer.h"
#include <iostream>
#include <fstream>

class ServerFarm {
private:
	WebServer* farm;
	unsigned size;
	unsigned capacity;
	char* name;
	void copy(const ServerFarm& other);
	void destroy();
	void resize();
public:
	ServerFarm();
	ServerFarm(int capacity);
	ServerFarm(const char* _name);
	ServerFarm(const ServerFarm& other);
	ServerFarm& operator =(const ServerFarm& other);
	~ServerFarm();
	ServerFarm& addServer(const WebServer newServer);
	void print() const;
	ServerFarm& operator -=(int* address);
	int countInNetwork(int address) const;
	void findMaxNetwork() const;
	ServerFarm& sort();

	//exercise
	void save(const char* fileName);
	void read(const char* fileName);
	//binary
	void saveBin(const char* fileName);
	void readBin(const char* fileName);

};