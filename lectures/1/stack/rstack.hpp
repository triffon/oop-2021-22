#ifndef __RSTACK_HPP
#define __RSTACK_HPP
#include <cstddef>
#include "abstract_stack.hpp"


class ResizingStack : public AbstractStack<int> {
private:
    static const int EMPTY_STACK = -1;
    static const int INITSTACK = 10;

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

    // копиране на стека
    void copyData(ResizingStack const&);
public:
    // създаване на празен стек
    ResizingStack();

    // конструктор за копиране
    ResizingStack(ResizingStack const&);

    // операция за присвояване
    ResizingStack& operator=(ResizingStack const&);

    // деструктор
    ~ResizingStack();

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