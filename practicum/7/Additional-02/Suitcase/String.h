#pragma once
#include <cstring>
#include <iostream>
class String {
public:
	String() {
		str = new char[1];
		str[0] = '\0';
	}

	String(const char* str) {
		this->str = new char[strlen(str) + 1];
		strcpy_s(this->str, strlen(str) + 1, str);
	}

	String(const String& other) {
		this->str = new char[strlen(other.str) + 1];
		strcpy_s(this->str, strlen(other.str) + 1, other.str);
	}

	String& operator=(const String& other) {
		if (this != &other) {
			this->str = new char[strlen(other.str) + 1];
			strcpy_s(this->str, strlen(other.str) + 1, other.str);
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const String& str);

	friend bool operator==(const String& lhs, const String& rhs);
private:
	char* str;
};

std::ostream& operator<<(std::ostream& out, const String& str) {
	out << str.str;
	return out;
}

bool operator==(const String& lhs, const String& rhs) {
	return !(strcmp(lhs.str, rhs.str));
}