#include <cassert>
#include <iostream>
#include "rstack.hpp"

// създаване на празен стек
ResizingStack::ResizingStack() : capacity(INITSTACK), top(EMPTY_STACK) {
    // заделяме първоначален размер
    stack = new int[capacity];
}

ResizingStack::ResizingStack(ResizingStack const& other)
  : top(other.top), capacity(other.capacity) {
    stack = new int[capacity];
    for(int i = 0; i <= top; i++)
        stack[i] = other.stack[i];
}

// проверка за празнота
bool ResizingStack::empty() const {
    return top == EMPTY_STACK;
}

// включване на елемент
void ResizingStack::push(int x) {
    if (full())
        resize();
    stack[++top] = x;
}

// намиране на последния включен елемент
int ResizingStack::peek() const {
    assert(!empty());
    return stack[top];
}

// изключване на последния включен елемент
int ResizingStack::pop() {
    assert(!empty());
    return stack[top--];
}

bool ResizingStack::full() const {
    return top == capacity - 1;
}

void ResizingStack::resize() {
    // разчитаме, че викаме resize само когато стекът е пълен
    size_t newcapacity = 2 * capacity;
    std::cerr << "Разширяваме стека до " << newcapacity << std::endl;
    int* newstack = new int[newcapacity];
    for(int i = 0; i < capacity; i++)
        newstack[i] = stack[i];
    capacity = newcapacity;
    delete[] stack;
    stack = newstack;
}