#include "money.h"

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