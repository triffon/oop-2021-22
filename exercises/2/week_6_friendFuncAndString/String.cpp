#include "String.h"

String::~String()
{
	delete[] myString;
}

size_t String::getSize() const
{
	return strlen(myString);
}

void String::print() const
{
	std::cout << myString;
}

void String::add(const char* str)
{
	char* temp = new char[strlen(myString) + strlen(str) + 1];
	strcpy_s(temp, strlen(myString) + strlen(str) + 1, myString);
	strcat_s(temp, strlen(myString) + strlen(str) + 1, str);
	delete myString;
	myString = temp;
}

String::String()
{
	myString = new char[1];
	myString[0] = '\0';
}

String::String(const char* str)
{
	myString = new char[strlen(str) + 1];
	strcpy_s(myString, strlen(str) + 1, str);
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	//int size = str.getSize();
	//for (int i = 0; i < size; i++)
	//{
	//	out << str.myString[i];
	//}
	out << str.myString;
	return out;
}

std::istream& operator>>(std::istream& in, const String& str)
{
	in >> str;
	return in;
}
