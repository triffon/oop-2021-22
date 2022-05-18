#pragma once
#include "Bus.cpp"
#include <stdexcept>
class BusStation
{
private:
    Bus **buses;
    unsigned capacity;
    unsigned count;
    void copyFrom(const BusStation &source);
    void erase();
    bool alreadyExists(const Bus &bus) const;

public:
    BusStation();
    BusStation(const BusStation &source);
    BusStation &operator=(const BusStation &rhs);
    ~BusStation();

    void parkBus(Bus &bus);
    bool sitPassanger();
};

bool BusStation::alreadyExists(const Bus &bus) const
{
    for (int i = 0; i < capacity; i++)
    {
        if (buses[i] != nullptr && buses[i] == &bus)
        {
            return true;
        }
    }
    return false;
}

void BusStation::parkBus(Bus &bus)
{
    if (count == capacity)
    {
        // resize();
    }
    if (alreadyExists(bus))
    {
        throw std::invalid_argument("Already parked that one");
    }
    for (int i = 0; i < capacity; i++)
    {
        if (buses[i] == nullptr)
        {
            buses[i] = &bus;
            count++;
            break;
        }
    }
}

bool BusStation::sitPassanger()
{
    if (count == 0)
    {
        return false;
    }
    for (int i = 0; i < capacity; i++)
    {
        if (buses[i] != nullptr)
        {
            if (buses[i]->sitPassanger())
            {
                if (buses[i]->full())
                {
                    delete buses[i];
                    buses[i] = nullptr;
                    count--;
                }
                return true;
            }
        }
    }
    return false;
}