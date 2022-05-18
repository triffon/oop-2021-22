#include "computerShop.h"
#include <iostream>

ComputerShop::ComputerShop(const std::string& name) : name(name) {}

void ComputerShop::addComputer(const Computer& computer)
{
    for (std::size_t i = 0; i < this->computers.getSize(); ++i)
    {
        if (computer.getBrand() == this->computers[i].getBrand())
        {
            this->computers[i].increaseQuantityBy(computer.getQuantity());
            return;
        }
    }

    this->computers.add(computer);
}

void ComputerShop::print()
{
    std::cout << this->name << std::endl;
    std::cout << this->computers << std::endl;
}

void ComputerShop::buyComputer(const std::string& brand, double customerMoney)
{
    int index = -1;

    for (std::size_t i = 0; i < this->computers.getSize(); ++i)
    {
        if (brand == this->computers[i].getBrand())
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        std::cout << "There aren't any computers with such brand in the shop" << std::endl;
        return;
    }

    if (customerMoney < this->computers[index].getPrice())
    {
        std::cout << "Not enough money" << std::endl;
        return;
    }

    this->computers[index].decreaseQuantity();

    if (this->computers[index].getQuantity() == 0)
    {
        this->computers.removeAt(index);
    }
}

List<Computer> ComputerShop::filter(filterFunction func)
{
    List<Computer> result;

    for (std::size_t i = 0; i < this->computers.getSize(); ++i)
    {
        if (func(this->computers[i]))
        {
            result.add(this->computers[i]);
        }
    }

    return result;
}