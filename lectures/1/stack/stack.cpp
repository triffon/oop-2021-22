#include <cassert>
#include "stack.hpp"

// създаване на празен стек
Stack::Stack() {
    top = EMPTY_STACK;
}

// проверка за празнота
bool Stack::empty() const {
    return top == EMPTY_STACK;
}

// включване на елемент
void Stack::push(int x) {
    assert(!full());
    stack[++top] = x;
}

// намиране на последния включен елемент
int Stack::peek() const {
    assert(!empty());
    return stack[top];
}

// изключване на последния включен елемент
int Stack::pop() {
    assert(!empty());
    return stack[top--];
}

bool Stack::full() const {
    return top == MAXSTACK - 1;
}