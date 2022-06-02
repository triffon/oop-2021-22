#pragma once

#include <iostream>
#include <cassert>

template <class T>
class List
{
private:
    static const std::size_t INITIAL_CAPACITY = 2;
    static const std::size_t INCREASE_STEP = 2;

    T* data;
    std::size_t size;
    std::size_t capacity;

    bool contains(const T& element) const;
    void copy(const List<T>& other);
    void deallocate();
    void resize();

public:
    List();
    List(const List<T>& other);
    List& operator = (const List<T>& other);
    ~List();

    void add(const T& element);
    void removeAt(std::size_t index);

    const T& operator [] (std::size_t index) const;
    T& operator [] (std::size_t index);

    std::size_t getSize() const;
    std::size_t getCapacity() const;
    bool isEmpty() const;

    template <class U>
    friend std::istream& operator >> (std::istream& in, List<U>& list);
    
    template <class U>
    friend std::ostream& operator << (std::ostream& out, const List<U>& list);
};

template <class T>
List<T>::List() : data(new T[List<T>::INITIAL_CAPACITY]), 
      capacity(List<T>::INITIAL_CAPACITY), size(0) {}

template <class T>
void List<T>::copy(const List<T>& other)
{
    this->data = new T[other.capacity];
    
    for (std::size_t i = 0; i < other.size; ++i)
    {
        this->data[i] = other.data[i];
    }

    this->capacity = other.capacity;
    this->size = other.size;
}

template <class T>
void List<T>::deallocate()
{
    delete[] this->data;
}

template <class T>
List<T>::List(const List<T>& other)
{
    this->copy(other);
}

template <class T>
List<T>& List<T>::operator = (const List<T>& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

template <class T>
List<T>::~List()
{
    this->deallocate();
}

template <class T>
bool List<T>::contains(const T& element) const
{
    for (std::size_t i = 0; i < this->size; ++i)
    {
        if (this->data[i] == element)
        {
            return true;
        }
    }

    return false;
}

template <class T>
void List<T>::resize()
{
    T* newData = new T[this->capacity * List<T>::INCREASE_STEP];

    for (std::size_t i = 0; i < this->size; ++i)
    {
        newData[i] = this->data[i];
    }

    this->capacity *= List<T>::INCREASE_STEP;
    this->deallocate();
    this->data = newData;
}

template <class T>
void List<T>::add(const T& element)
{
    if (contains(element))
    {
        return;
    }

    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->data[this->size++] = element;
}

template <class T>
void List<T>::removeAt(std::size_t index)
{
    if (index >= this->size)
    {
        throw std::invalid_argument("There isn't an element with such index");
    }

    std::swap(this->data[index], this->data[--this->size]);
}

template <class T>
const T& List<T>::operator [] (std::size_t index) const
{
    if (index >= this->size)
    {
        throw std::invalid_argument("Invalid index");
    }

    return this->data[index];
}

template <class T>
T& List<T>::operator [] (std::size_t index)
{
    if (index >= this->size)
    {
        throw std::invalid_argument("Invalid index");
    }

    return this->data[index];
}

template <class T>
std::size_t List<T>::getSize() const
{
    return this->size;
}

template <class T>
std::size_t List<T>::getCapacity() const
{
    return this->capacity;
}

template <class T>
bool List<T>::isEmpty() const
{
    return this->size == 0;
}

template <class T>
std::istream& operator >> (std::istream& in, List<T>& list)
{
    list.deallocate();

    in >> list.capacity;
    list.size = 0;
    list.data = new T[list.capacity];
    in.ignore();

    for (std::size_t i = 0; i < list.capacity; ++i)
    {
        T temp;
        in >> temp;
        if (!list.contains(temp))
        {
            list.data[list.size++] = temp;
        }
    }

    return in;
}

template <class T>
std::ostream& operator << (std::ostream& out, const List<T>& list)
{
    out << list.size << '\n';
    for (std::size_t i = 0; i < list.size; ++i)
    {
        out << list.data[i] << " ";
    }

    return out;
}