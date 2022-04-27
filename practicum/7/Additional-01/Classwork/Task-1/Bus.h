#pragma once
#include <cstring>
class Bus
{
private:
    char *licensePlate;
    unsigned capacity;
    unsigned pasangers;
    void copyFrom(const Bus &source);
    void erase();

public:
    Bus(const char *plate = "\0", unsigned cap = 10, unsigned pas = 0);
    Bus(const Bus &source);
    Bus &operator=(const Bus &rhs);
    Bus(Bus &&src);
    Bus &operator=(Bus &&rhs);
    ~Bus();

    bool sitPassanger();
    bool full() const;
};




