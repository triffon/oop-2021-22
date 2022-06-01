#pragma once
#include <iostream>

template<typename T>
struct ListNode {
	T data;
	ListNode<T>* next;
	ListNode(T _data, ListNode<T>* _next = nullptr) : data(_data) {
		next = _next;
	};
};

template<typename T>
class List {
private:
	ListNode<T>* start;
	ListNode<T>* end;
	void destroy();
	void copy(const List& other);
public:
	List();
	List(const List& other);
	List<T>& operator=(const List& other);
	~List();
	void addEl(T element);
	void print() const;
};

template<typename T>
inline void List<T>::destroy()
{
	while (start)
	{
		ListNode<T>* temp = start;
		start = start->next;
		delete temp;
	}
}

template<typename T>
inline void List<T>::copy(const List& other)
{
	if (other.start == nullptr)
	{
		return;
	}
	start = new ListNode<T>(other.start->data);
	end = start;
	ListNode<T>* current = other.start->next;
	while (current)
	{
		addEl(current->data);
		current = current->next;
	}

}

template<typename T>
inline List<T>::List()
{
	start = end = nullptr;
}

template<typename T>
inline List<T>::List(const List& other)
{
	copy(other);
}

template<typename T>
inline List<T>& List<T>::operator=(const List& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}


template<typename T>
inline List<T>::~List()
{
	destroy();
}

template<typename T>
inline void List<T>::addEl(T element)
{
	if (end == nullptr)
	{
		start = end = new ListNode<T>(element);
	}
	else
	{
		ListNode<T>* newEl = new ListNode<T>(element);
		end->next = newEl;
		end = newEl;
	}
}

template<typename T>
inline void List<T>::print() const
{
	ListNode<T>* current = start;
	while (current != nullptr)
	{
		std::cout << current->data;
		std::cout << " -> ";
		current = current->next;
	}
}
