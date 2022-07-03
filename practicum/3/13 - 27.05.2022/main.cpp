#include "JSON.hpp"
#include <iostream>

int main() {
    JSONObj tefter;
    tefter.m["age"] = new JSONNumber<int>(12);
    JSONObj object;
    object.m["name"] = new JSONString("pesho");
    object.m["age"] = new JSONNumber<int>(42);
    object.m["tefter"] = &tefter;
    object.m["array"] = new JSONArr(std::vector<JSONEntry *>{new JSONNumber<double>(1), new JSONArr(std::vector<JSONEntry *>())});
    object.print(std::cout);

    std::cout << "Hello World!\n";
}
