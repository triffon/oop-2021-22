#pragma once

#pragma once
#include <iostream>

template <typename T>
class DynamicArray {
private:
	T* arr;
	int size;
	int capacity;
	bool resize();
	void copy(const DynamicArray<T>& other);
public:
	DynamicArray()
	{
		capacity = 20;
		size = 0;
		arr = new T[capacity];
	}
	DynamicArray(int cap)
	{
		capacity = cap;
		size = 0;
		arr = new T[cap];
	}
	DynamicArray(const DynamicArray<T>& other);
	DynamicArray<T>& operator =(const DynamicArray<T>& other);
	~DynamicArray()
	{
		delete[] arr;
	}

	bool pushBack(const T& el)
	{
		if (capacity == size)
		{
			return resize();
		}
		arr[size++] = el;
		return true;
	}

	void pop()
	{
		size--;
	}
	void removeAt(const T& el, int ind)
	{
		int i = 0;
		for (; i < size, arr[i] != ind; i++) {}
		std::swap(arr[i], arr[size]);
		pop();
	}
	T getAt(int ind)
	{
		return arr[ind];
	}
	void setAt(const T&, int);
	void printInfo();
	T& operator [] (int ind)
	{
		return arr[ind];
	}
	const T operator [](int ind) const {
		return arr[ind];
	}
	bool empty()const;
	int getSize()const {
		return size;
	}
	void shrink_to_fit();
};

template<typename T>
inline bool DynamicArray<T>::resize()
{
	capacity *= 2;
	T* temp = new T[capacity];
	if (temp == nullptr)
	{
		return false;
	}
	for (int i = 0; i < size;i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	return true;
}

template<typename T>
inline void DynamicArray<T>::copy(const DynamicArray<T>& other)
{
	capacity = other.capacity;
	size = other.size;
	arr = new T[capacity];
	for (int i = 0; i < size;i++)
	{
		arr[i] = other.arr[i];
	}
}

template<typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
	copy(other);
}

template<typename T>
inline DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	if (this != &other)
	{
		delete[] arr;
		copy(other);
	}
	return *this;
}
