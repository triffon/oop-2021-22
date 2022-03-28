#pragma once
#include "WebServer.h"

class ServerFarm {
private:
	WebServer* farm;
	unsigned size;
	unsigned capacity;
	char* name;
	void copy(const ServerFarm& other);
	void destroy();
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


};