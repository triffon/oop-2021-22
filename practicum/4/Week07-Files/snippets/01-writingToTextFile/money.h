#pragma once

#include <iostream>

class Money
{
private:
    unsigned int levs;
    unsigned int stotinkas;

public:
    Money(unsigned int levs = 0, unsigned int stotinkas = 0);

    friend std::istream& operator >> (std::istream& in,  Money& money);
    friend std::ostream& operator << (std::ostream& out, const Money& money);
};