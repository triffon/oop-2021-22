#pragma once
#include <iostream>
#include <cstring>

class String {
private:
	char* myString;
	void copy(const String& other);
	void erase();
public:
	String();
	String(const char* str);
	String(const String& other);
	String& operator =(const String& other);
	~String();
	size_t getSize() const;
	void print() const;
	void add(const char* str);
	String operator+(const String& other);
	friend std::ostream& operator << (std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& in, const String& str);
};