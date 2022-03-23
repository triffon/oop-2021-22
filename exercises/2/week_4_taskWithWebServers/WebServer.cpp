#include "WebServer.h"
#include <iostream>

bool WebServer::operator<(const WebServer& other)
{
	for (int i = 0; i < 4; i++)
	{

	}
}

bool WebServer::operator==(const WebServer& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->IPv4Address[i] != other.IPv4Address[i]) {
			return false;
		}
	}
	if (strcmp(OS, other.OS) != 0)
	{
		return false;
	}
	if (strcmp(URL, other.URL) != 0)
	{
		return false;
	}
	return true;
}

bool WebServer::operator!=(const WebServer& other)
{
	return !(*this == other);
}

void WebServer::print() const
{
	std::cout << URL << '\n';
	for (int i = 0; i < 3; i++)
	{
		std::cout << IPv4Address[i] << '.';
	}
	std::cout << IPv4Address[3] << '\n';
	std::cout << OS << '\n';
}

void WebServer::read()
{
	std::cin >> URL;
	for (int i = 0; i < 4; i++)
	{
		std::cin >> IPv4Address[i];
	}
	std::cin >> OS;
}
