#pragma once


struct WebServer {
	char URL[501];
	int IPv4Address[4];
	char OS[21];
	bool operator <(const WebServer& other);
	bool operator ==(const WebServer& other);
	bool operator !=(const WebServer& other);
	void print() const;
	void read();

};