#pragma once
#include "JSONEntry.hpp"
#include <string>

class JSONString : public JSONEntry {
  public:
    std::string value;
    JSONString(const char *value);
    virtual void print(std::ostream &);
    virtual ~JSONString() {}
};

inline JSONString::JSONString(const char *value) {
    this->value = value;
}

void JSONString::print(std::ostream &os) {
    os << value;
}