#ifndef __STACK_HPP
#define __STACK_HPP
#include "abstract_stack.hpp"

class Stack : public AbstractStack<int> {
private:
    static const int MAXSTACK = 100;
    static const int EMPTY_STACK = -1;


    // стекът
    int stack[MAXSTACK];

    // индекс на послдния включен елемент
    int top;

    // проверка дали стек е запълнен на максимален капацитет
    bool full() const;
public:
    // създаване на празен стек
    Stack();

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(int const& x);

    // намиране на последния включен елемент
    int const& peek() const;

    // изключване на последния включен елемент
    int pop();
};

#endif