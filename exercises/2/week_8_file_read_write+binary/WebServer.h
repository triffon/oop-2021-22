#pragma once
#include <fstream>

class WebServer {
private:
	char * URL;
	int IPv4Address[4];
	char * OS;
	void copy(const WebServer& other);
	void destroy();
public:
	WebServer();
	WebServer(const WebServer& other);
	WebServer& operator =(const WebServer& other);
	~WebServer();
	bool operator <(const WebServer& other);
	bool operator ==(const WebServer& other);
	bool operator !=(const WebServer& other);
	void print() const;
	void read();

	// for exercise:
	void save(std::ostream& out);
	void read(std::istream& in);
	//binary
	void saveBin(std::ostream& out);
	void readBin(std::istream& in);
};