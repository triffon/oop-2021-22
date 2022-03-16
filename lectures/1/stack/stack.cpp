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
    stack[++top] = x;
}

// намиране на последния включен елемент
int Stack::peek() const {
    return stack[top];
}

// изключване на последния включен елемент
int Stack::pop() {
    return stack[top--];
}
