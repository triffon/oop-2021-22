#include "money.h"

Money::Money() : levs(0), stotinkas(0) {}

std::istream& operator >> (std::istream& in, Money& money)
{
    std::cout << "Enter levs: ";
    in >> money.levs;
    std::cout << "Enter stotinkas: ";
    in >> money.stotinkas;

    return in;
}

std::ostream& operator << (std::ostream& out, const Money& money)
{
    out << money.levs << " levs and " << money.stotinkas << " stotinkas"; 

    return out;
}