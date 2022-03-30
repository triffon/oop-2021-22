#include <cassert>
#include <iostream>
#include "lstack.hpp"

// създаване на празен стек
LinkedStack::LinkedStack() : top(nullptr) {}

// копиране на стек
LinkedStack::LinkedStack(LinkedStack const& other) : top(nullptr) {
    if (other.top != nullptr) {
        // other не е празен
        StackElement* lastAdded = top = new StackElement{other.top->data, nullptr};
        StackElement* nextToCopy = other.top->next;
        while (nextToCopy) {
            lastAdded = lastAdded->next = new StackElement{nextToCopy->data, nullptr};
            nextToCopy = nextToCopy->next;
        }
    }
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
