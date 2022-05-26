#ifndef __PRINTABLE_HPP
#define __PRINTABLE_HPP

#include <iostream>

class Printable {
public:
    virtual void print(std::ostream& os = std::cout) const = 0;
    virtual Printable* clone() const = 0;
    virtual ~Printable() {}

    void println(std::ostream& os = std::cout) const {
        print(os);
        os << std::endl;
    }
};

#endif