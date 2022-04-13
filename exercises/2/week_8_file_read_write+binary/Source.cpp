#include <iostream>
#include <fstream>
#include "ServerFarm.h"
#include "WebServer.h";

int main() {
	WebServer server;
	//server.read();
	//server2.read();
	//server.print();
	//server2.print();
	//std::cout << (server < server2);
	//std::cout << (server == server2);

	//std::ofstream out;
	//out.open("test.txt");
	//if (out) {
	//	server.save(out);
	//}
	//out.close();

	//std::ifstream in;
	//in.open("test.txt");
	//if (in) {
	//	server.read(in);
	//}
	//in.close();

	//server.print();
	ServerFarm farm;
	//farm.addServer(server);
	//farm.addServer(server);
	//farm.addServer(server);
	//farm.addServer(server).addServer(server).sort().print();
	//farm.readBin("testBin.dat");
	//farm.print();

	enum State {NONE = 0, SLEEP = 1, RUNNING = 2};

	State s;
	s = State(3);

	std::cout << s;


	return 0;
}