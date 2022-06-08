#pragma once

class BigFour {
private:
	int a;
	double b;
	char c;
	int* arr;
	int size, capacity;
	char* str;
	char** strArr;
	int sizeStrArr, capacityStrArr;
	void copy(const BigFour& other) {
		a = other.a;
		b = other.b;
		c = other.c;
		size = other.size;
		capacity = other.capacity;
		sizeStrArr = other.sizeStrArr;
		capacityStrArr = other.capacityStrArr;
		arr = new int[capacity];
		for (int i = 0; i < size;i++)
		{
			arr[i] = other.arr[i];
		}
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str) + 1, other.str);
		strArr = new char* [capacityStrArr];
		for (int i = 0; i < size;i++)
		{
			strArr[i] = new char[strlen(other.strArr[i]) + 1];
			strcpy_s(strArr[i], strlen(other.strArr[i]) + 1, other.strArr[i]);
		}
	}
	void destroy()
	{
		delete[] arr;
		delete[] str;
		for (int i = 0; i < sizeStrArr;i++)
		{
			delete[] strArr[i];
		}
		delete[] strArr;
	}
public:
	BigFour()
	{
		a = 0;
		b = 0.0;
		c = ' ';
		arr = nullptr;
		size = 0;
		capacity = 0;
		sizeStrArr = 0;
		capacityStrArr = 0;
		str = nullptr;
		strArr = nullptr;
	}
	BigFour(int _a, double _b, char _c, int* _arr, int length, const char* _str, char** _strArr, int strArrLength)
	{
		a = _a;
		b = _b;
		c = _c;
		size = length;
		capacity = length;
		arr = new int[size];
		for (int i = 0; i < size;i++)
		{
			arr[i] = _arr[i];
		}
		sizeStrArr = strArrLength;
		capacityStrArr = strArrLength;
		str = new char[strlen(_str) + 1];
		strcpy_s(str, strlen(_str) + 1, _str);
		strArr = new char* [strArrLength];
		for (int i = 0; i < strArrLength;i++)
		{
			strArr[i] = new char[strlen(_strArr[i]) + 1];
			strcpy_s(strArr[i], strlen(_strArr[i]) + 1, _strArr[i]);
		}
	}
	BigFour(const BigFour& other)
	{
		copy(other);
	}
	BigFour& operator=(const BigFour& other)
	{
		if (this != &other)
		{
			destroy();
			copy(other);
		}
	}
	~BigFour()
	{
		destroy();
	}
	void setArr(const char* _str) {
		if (str) {
			delete[] str;
		}
		str = new char[strlen(_str) + 1];
		strcpy_s(str, strlen(_str) + 1, _str);
	}
	void setA(int _a)
	{
		a = _a;
	}
};