#include "BusStation.h"

void BusStation::copyFrom(const BusStation &source)
{
    /*
    int index = 0;
    for(...){
        if(source.buses[i] != nullptr){
            buses[index++] = source.buses[i];
        }    
    }
    }
    count = index;
    */
    capacity = source.capacity;
    buses = new Bus*[capacity];

    for (int i = 0; i < capacity; i++)
    {
        buses[i] = source.buses[i];
    }
    count = source.count;
}


BusStation::BusStation() 
    : count(0), capacity(10), buses(new Bus*[capacity])
{
    for (int i = 0; i < capacity; i++)
    {
        buses[i] = nullptr;
    }   
}

BusStation::BusStation(const BusStation &source)
{
    copyFrom(source);
}

BusStation &BusStation::operator=(const BusStation &rhs)
{
    if(this != &rhs){
        erase();
        copyFrom(rhs);
    }
    return *this;
}

void BusStation::erase()
{
    for (int i = 0; i < capacity; i++)
    {
        delete buses[i];
    }
    delete[] buses;    
}

BusStation::~BusStation()
{
    erase();
}