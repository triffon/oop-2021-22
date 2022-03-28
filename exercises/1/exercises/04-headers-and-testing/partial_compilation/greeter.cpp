#include "greeter.hpp"

#include <iostream>

void Greeter::print() const
{
    std::cout << "Zdr, " << m_world.name() << '\n';
}
