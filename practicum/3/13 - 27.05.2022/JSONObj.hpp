#pragma once
#include "JSONEntry.hpp"
#include <iostream>
#include <map>
#include <string>

class JSONObj : public JSONEntry {
  public:
    std::map<std::string, JSONEntry *> m;

    virtual void print(std::ostream &out) {
        for (const auto &n : m) {
            out << n.first << " : ";
            n.second->print(out);
            out << std::endl;
        }
    }
    virtual ~JSONObj() = default;
};