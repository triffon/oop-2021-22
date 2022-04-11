#include "money.h"

Money::Money(unsigned int levs, unsigned int stotinkas) 
    : levs(levs), stotinkas(stotinkas) {}

std::istream& operator >> (std::istream& in, Money& money)
{
    in >> money.levs >> money.stotinkas;

    return in;
}

std::ostream& operator << (std::ostream& out, const Money& money)
{
    out << money.levs << " levs and " << money.stotinkas << " stotinkas"; 

    return out;
}