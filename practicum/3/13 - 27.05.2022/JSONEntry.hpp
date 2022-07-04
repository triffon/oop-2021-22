#pragma once
#include <fstream>

struct JSONEntry {
    virtual void print(std::ostream &) = 0;
    virtual ~JSONEntry() {}
};