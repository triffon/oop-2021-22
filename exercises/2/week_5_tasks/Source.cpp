#include <iostream>
#include "ServerFarm.h"
#include "WebServer.h";
#include "SumAvgCalculator.h"

int main() {
	//WebServer server, server2;
	//server.read();
	//server2.read();
	//server.print();
	//server2.print();
	//std::cout << (server < server2);
	//std::cout << (server == server2);

	//ServerFarm farm;
	//farm.addServer(server);
	//farm.addServer(server);
	//farm.addServer(server);
	//farm.addServer(server2).addServer(server).sort().print();

	SumAvgCalculator c(10), p(5), k(3);
	c.add(10);
	c.add(5);
	c.sub(15);

	std::cout << c.sum() << "  " << c.avarage() << '\n';

	p = c + k;
	std::cout << p.sum() << "  " << p.avarage() << '\n';

	p += c;
	std::cout << p.sum() << "  " << p.avarage() << '\n';

	return 0;
}