#include <iostream>
#include <fstream>
#include "list.h"

int main ()
{
    List<int> list;

    list.add(2);
    list.add(5);
    list.add(7);
    list.add(-1);

    std::cout << list[2] << std::endl;

    std::cout << list << std::endl;

    List<std::string> stringList;

    std::cin >> stringList;
    std::cout << stringList << std::endl;

    List<char> charList;

    std::ifstream in("charList.txt");
    in >> charList;

    std::ofstream out("charList-res.txt");
    out << charList;

    return 0;
}