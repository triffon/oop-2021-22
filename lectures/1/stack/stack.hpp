#ifndef __STACK_HPP
#define __STACK_HPP

const int MAXSTACK = 100;

class Stack {
private:
    // стекът
    int stack[MAXSTACK];
    
    // индекс на послдния включен елемент
    int top;
public:
    // създаване на празен стек
    Stack();

    // проверка за празнота
    bool empty() const;

    // включване на елемент
    void push(int x);

    // намиране на последния включен елемент
    int peek() const;

    // изключване на последния включен елемент
    int pop();
};

#endif