#include <iostream>
#include "ServerFarm.h"
#include "WebServer.h";

int main() {
	WebServer server, server2;
	server.read();
	server2.read();
	server.print();
	server2.print();
	std::cout << (server < server2);
	std::cout << (server == server2);

	ServerFarm farm;

	return 0;
}