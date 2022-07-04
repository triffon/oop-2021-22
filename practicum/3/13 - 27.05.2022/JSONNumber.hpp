#pragma once
#include "JSONEntry.hpp"

template <typename T>
class JSONNumber : public JSONEntry {
  public:
    JSONNumber(T num);
    T value;
    virtual void print(std::ostream &);
    virtual ~JSONNumber() {}
};

template <typename T>
void JSONNumber<T>::print(std::ostream &os) {
    os << value;
}

template <typename T>
JSONNumber<T>::JSONNumber(T num) {
    this->value = num;
}