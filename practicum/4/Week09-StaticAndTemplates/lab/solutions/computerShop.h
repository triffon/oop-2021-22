#pragma once

#include "computer.h"
#include "list.h"
#include <string>

typedef bool (*filterFunction) (const Computer& computer);

class ComputerShop
{
private:
    std::string name;
    List<Computer> computers;

public:
    ComputerShop(const std::string& name);

    void addComputer(const Computer& computer);
    void print();
    void buyComputer(const std::string& brand, double customerMoney);

    List<Computer> filter(filterFunction func);
};