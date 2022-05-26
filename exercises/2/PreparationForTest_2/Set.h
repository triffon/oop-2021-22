#pragma once
#include <iostream>

class IntSet {
public:
	virtual bool member(int x) const = 0;
	virtual int get(int i) const = 0;
	virtual bool operator <(const IntSet* s) const = 0;
	virtual bool operator *(const IntSet* s) const = 0;
};

class IntRange : public IntSet {
private:
	int a, b;
public:
	IntRange(int _a, int _b) {
		if (_a > _b)
		{
			a = _b;
			b = _a;
		}
		else
		{
			a = _a;
			b = _b;
		}
	}
	bool member(int x) const override {
		if (x >= a && x <= b)
		{
			return true;
		}
		return false;
	}
	int get(int i) const {
		return a + i;
	}
	bool operator <(const IntSet* s) const override{
		for (int i = a + 1; i < b; i++)
		{
			if (!s->member(i))
			{
				return false;
			}
		}
		return true;
	}
	bool operator*(const IntSet* s) const override {
		for (int i = a + 1; i < b; i++)
		{
			if (s->member(i))
			{
				return true;
			}
		}
		return false;
	}
};

class ArraySet : public IntSet {
private:
	int* set;
	int size, capacity;
public:
	ArraySet(int n)
	{
		capacity = n;
		size = 0;
		set = new int[capacity];
	}
	//big 4
	bool insert(int x)
	{
		if (size == capacity)
		{
			return false;
		}
		set[size++] = x;
		return true;
	}
	bool remove(int x)
	{
		for (int i = 0; i < size;i++)
		{
			if (set[i] == x)
			{
				std::swap(set[i], set[size - 1]);
				size--;
				return true;
			}
		}
		return false;
	}
	bool member(int x) const override {
		for (int i = 0; i < size;i++)
		{
			if (set[i] == x)
			{
				return true;
			}
		}
		return false;
	}
	int get(int i) const override {
		return set[i];
	}
	bool operator <(const IntSet* s) const override {
		for (int i = 0; i < size; i++)
		{
			if (!s->member(i))
			{
				return false;
			}
		}
		return true;
	}
	bool operator*(const IntSet* s) const override {
		for (int i = 0; i < size; i++)
		{
			if (s->member(i))
			{
				return true;
			}
		}
		return false;
	}
};