#ifndef __RSTACK_HPP
#define __RSTACK_HPP
#include <cstddef>

const int INITSTACK = 10;
const int EMPTY_STACK = -1;

class ResizingStack {
private:
    // указател към масива на стека
    int* stack;

    // индекс на послдния включен елемент
    int top;

    // капацитет на стека
    size_t capacity;

    // проверка дали стек е запълнен на максимален капацитет
    bool full() const;

    // разширяване на стека
    void resize();
public:
    // създаване на празен стек
    ResizingStack();

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