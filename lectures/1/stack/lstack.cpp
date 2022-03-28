#include <cassert>
#include <iostream>
#include "lstack.hpp"

// създаване на празен стек
LinkedStack::LinkedStack() {
    top = nullptr;
}

// проверка за празнота
bool LinkedStack::empty() const {
    return top == nullptr;
}

// включване на елемент
void LinkedStack::push(int x) {
    top = new StackElement{x, top};
    /*
    newtop->data = x;
    newtop->next = top;
    top = newtop;
    */
}

// намиране на последния включен елемент
int LinkedStack::peek() const {
    assert(!empty());
    return top->data;
}

// изключване на последния включен елемент
int LinkedStack::pop() {
    assert(!empty());
    StackElement* newtop = top->next;
    int x = top->data;
    delete top;
    top = newtop;
    return x;
}
