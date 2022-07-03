#pragma once
#include "JSONEntry.hpp"
#include <vector>

class JSONArr : public JSONEntry {
  public:
    std::vector<JSONEntry *> arr;
    JSONArr(std::vector<JSONEntry *> arr);
    virtual void print(std::ostream &out) {
        out << "[ ";
        for (auto &x : arr) {
            x->print(out);
            out << ", ";
        }
        out << "]";
    }
    virtual ~JSONArr() = default;
};

JSONArr::JSONArr(std::vector<JSONEntry *> arr) {
    this->arr = arr;
}