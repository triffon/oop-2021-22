#include "money.h"
#include <iostream>
#include <cassert>

Money::Money(const unsigned int levs, const unsigned int stotinkas)
{
    this->levs = levs;
    this->stotinkas = stotinkas;
}

bool Money::operator == (const Money& other) const
{
    // return this->operator==(other);
    
    return this->levs == other.levs && this->stotinkas == other.stotinkas;
}

bool Money::operator != (const Money& other) const
{
    return !(*this == other);
}

bool Money::operator < (const Money& other) const
{
    return this->levs < other.levs || 
          (this->levs == other.levs && this->stotinkas < other.stotinkas);
}

Money& Money::operator -= (const Money& other)
{
    assert(other < *this);

    if (this->stotinkas < other.stotinkas)
    {
        this->stotinkas += 100;
        --this->levs;
    }

    this->levs -= other.levs;
    this->stotinkas -= other.stotinkas;

    return *this;
}

Money Money::operator - (const Money& other) const
{
    Money result = *this;
    result -= other; // you can use the already defined operators

    return result;
}

void Money::print() const
{
    std::cout << this->levs << ":" << this->stotinkas << std::endl;
}