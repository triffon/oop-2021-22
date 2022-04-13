#include "WebServer.h"
#include <iostream>

void WebServer::copy(const WebServer& other)
{
	URL = new char[strlen(other.URL) + 1];
	strcpy_s(URL, strlen(other.URL) + 1, other.URL);
	IPv4Address[0] = other.IPv4Address[0];
	IPv4Address[1] = other.IPv4Address[1];
	IPv4Address[2] = other.IPv4Address[2];
	IPv4Address[3] = other.IPv4Address[3];
	OS = new char[strlen(other.OS) + 1];
	strcpy_s(OS, strlen(other.OS) + 1, other.OS);
}

void WebServer::destroy()
{
	delete[] URL;
	delete[] OS;
}

WebServer::WebServer()
{
	URL = new char[15];
	strcpy_s(URL, 15, "www.google.com");
	IPv4Address[0] = 0;
	IPv4Address[1] = 0;
	IPv4Address[2] = 0;
	IPv4Address[3] = 0;
	OS = new char[8];
	strcpy_s(OS, 8, "Windows");
}

WebServer::WebServer(const WebServer& other)
{
	copy(other);
}

WebServer& WebServer::operator=(const WebServer& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

WebServer::~WebServer()
{
	destroy();
}

bool WebServer::operator<(const WebServer& other)
{
	for (int i = 0; i < 4; i++)
	{

	}
	return true;
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
	destroy();
	char temp[128];
	std::cout << "Enter URL: ";
	std::cin >> temp;
	URL = new char[strlen(temp) + 1];
	strcpy_s(URL, strlen(temp) + 1, temp);
	std::cout << "Enter 4 digits: ";
	for (int i = 0; i < 4; i++)
	{
		std::cin >> IPv4Address[i];
	}
	std::cout << "Enter OS: ";
	std::cin >> temp;
	OS = new char[strlen(temp) + 1];
	strcpy_s(OS, strlen(temp) + 1, temp);
}

void WebServer::save(std::ostream& out)
{
	out << URL << ' ';
	for (int i = 0; i < 4; i++)
	{
		out << IPv4Address[i] << ' ';
	}
	out << OS << '\n';
}

//void WebServer::read(const char* line)
//{
//	int i = 0, count = 0, lastPos = 0;
//	while (line[i] != ' ')
//	{
//		count++;
//		i++;
//	}
//	URL = new char[count + 1];
//	for (int j = 0; j < i; j++)
//	{
//		URL[j] = line[lastPos++];
//	}
//	URL[lastPos++] = '\0';
//	i++;
//	count = 0;
//	for (int j = 0; j < 4; j++)
//	{
//		while (line[i] != ' ')
//		{
//			count++;
//			i++;
//		}
//	}
//
//}

void WebServer::read(std::istream& in)
{
	char* temp = nullptr;
	destroy();
	int count = 0;
	char c;
	do
	{
		in.get(c);
		count++;
	} while (c != ' ');
	URL = new char[count];
	temp = new char[count];
	in.seekg(-count, std::ios::cur);
	in >> temp;
	strcpy_s(URL, count, temp);
	in.get(c);
	for (int i = 0; i < 4; i++)
	{
		in >> IPv4Address[i];
		in.get(c);
	}
	count = 0;
	do
	{
		in.get(c);
		count++;
	} while (c != '\n');
	delete[] temp;
	temp = new char[count];
	OS = new char[count];
	in.seekg(-(count + 1), std::ios::cur);
	in >> temp;
	in.get(c);
	strcpy_s(OS, count, temp);

	delete[] temp;
}

void WebServer::saveBin(std::ostream& out)
{
	int size = strlen(URL);
	out.write((const char*)&size, sizeof(size));
	out.write(URL, size);
	for (int i = 0; i < 4; i++)
	{
		out.write((const char*)&IPv4Address[i], sizeof(int));
	}
	size = strlen(OS);
	out.write((const char*)&size, sizeof(size));
	out.write(OS, size);
}

void WebServer::readBin(std::istream& in)
{
	destroy();
	int size = 0;
	in.read((char*)&size, sizeof(int));
	URL = new char[size + 1];
	in.read(URL, size);
	URL[size] = '\0';

	for (int i = 0; i < 4; i++)
	{
		in.read((char*)&IPv4Address[i], sizeof(int));
	}
	in.read((char*)&size, sizeof(int));
	OS = new char[size + 1];
	in.read(OS, size);
	OS[size] = '\0';
}
