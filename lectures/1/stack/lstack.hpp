#ifndef __LSTACK_HPP
#define __LSTACK_HPP
#include <cstddef>

struct StackElement {
    int data;
    StackElement* next;
};

class LinkedStack {
private:
    // указател към двойната кутия, която е връх на стека
    StackElement* top;

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
    void push(int x);

    // намиране на последния включен елемент
    int peek() const;

    // изключване на последния включен елемент
    int pop();
};

#endif