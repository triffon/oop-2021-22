#ifndef __LSTACK_HPP
#define __LSTACK_HPP
#include <cassert>
#include <cstddef>
#include <iostream>

template <typename T>
struct StackElement {
    T data;
    StackElement<T>* next;
};

template <typename T>
class LinkedStack {
private:
    // указател към двойната кутия, която е връх на стека
    StackElement<T>* top;

    // копиране на стек
    void copyStack(LinkedStack const&);

    // изтриване на стек
    void erase();

public:
    // създаване на празен стек
    LinkedStack();

    // конструктор за копиране
    LinkedStack(LinkedStack const&);

    // операция за присвояване
    LinkedStack& operator=(LinkedStack const&);

    // деструктор
    ~LinkedStack();

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(T const& x);

    // намиране на последния включен елемент
    T const& peek() const;

    // изключване на последния включен елемент
    T pop();
};


// създаване на празен стек
template <typename T>
LinkedStack<T>::LinkedStack() : top(nullptr) {}

// копиране на стек
template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack const& other) : top(nullptr) {
    copyStack(other);
}

// деструктор
template <typename T>
LinkedStack<T>::~LinkedStack() {
    erase();
}

template <typename T>
void LinkedStack<T>::erase() {
    // !!! delete top;
    while (!empty()) pop();
    // домашно: реализирайте го директно с представянето
}

template <typename T>
void LinkedStack<T>::copyStack(LinkedStack const& other) {
    if (other.top != nullptr) {
        // other не е празен
        StackElement<T>* lastAdded = top = new StackElement<T>{other.top->data, nullptr};
        StackElement<T>* nextToCopy = other.top->next;
        while (nextToCopy) {
            lastAdded = lastAdded->next = new StackElement<T>{nextToCopy->data, nullptr};
            nextToCopy = nextToCopy->next;
        }
    }
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack const& other) {
    if (this != &other) {
        erase();
        copyStack(other);
    }
    return *this;
}


// проверка за празнота
template <typename T>
bool LinkedStack<T>::empty() const {
    return top == nullptr;
}

// включване на елемент
template <typename T>
void LinkedStack<T>::push(T const& x) {
    top = new StackElement<T>{x, top};
    /*
    newtop->data = x;
    newtop->next = top;
    top = newtop;
    */
}

// намиране на последния включен елемент
template <typename T>
T const& LinkedStack<T>::peek() const {
    assert(!empty());
    return top->data;
}

// изключване на последния включен елемент
template <typename T>
T LinkedStack<T>::pop() {
    assert(!empty());
    StackElement<T>* newtop = top->next;
    T x = top->data;
    delete top;
    top = newtop;
    return x;
}

#endif