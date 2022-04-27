#include "Bus.h"

Bus::Bus(const char * plate, unsigned int cap, unsigned int pas) 
    : licensePlate(new char[strlen(plate)+1]), capacity(cap), pasangers(pas)
{
    strncpy(licensePlate, plate, strlen(plate)+1);
}

void Bus::copyFrom(const Bus &source)
{
    capacity = source.capacity;
    pasangers = source.pasangers;
    size_t len = strlen(source.licensePlate)+1;
    licensePlate = new char[len];
    strncpy(licensePlate, source.licensePlate,len);
}

Bus::Bus(const Bus &source)
{
    copyFrom(source);
}

Bus &Bus::operator=(const Bus &rhs)
{
    if (this != &rhs)
    {
        erase();
        copyFrom(rhs);
    }
    return *this;
}

Bus::Bus(Bus &&src) : licensePlate(src.licensePlate), capacity(src.capacity), pasangers(src.pasangers)
{
    src.licensePlate = nullptr;
}

Bus &Bus::operator=(Bus &&rhs)
{
    if (this != &rhs)
    {
        erase();
        licensePlate = rhs.licensePlate;
        capacity = rhs.capacity;
        pasangers = rhs.pasangers;
        rhs.licensePlate = nullptr;
    }
    return *this;
}

void Bus::erase()
{
    delete[] licensePlate;
    licensePlate = nullptr;
}

Bus::~Bus()
{
    erase();
}

bool Bus::full() const
{
    return pasangers == capacity;
}

bool Bus::sitPassanger()
{
    if (full())
    {
        return false;
    }
    pasangers++;
    return true;
}