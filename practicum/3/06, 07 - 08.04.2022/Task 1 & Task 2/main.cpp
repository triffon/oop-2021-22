#include <fstream>
#include <iostream>

#include "DateTime.hpp"
#include "Event.hpp"
#include "Schedule.hpp"

int main() {
    std::ofstream out("date.txt");

    DateTime d(1, 2, 3, 4, 5);
    out << d << std::endl;

    out.close();

    /////////////////////////////////////////////////////////////////////

    std::ifstream in("date.txt");

    DateTime d1;
    in >> d1;
    std::cout << d1 << std::endl;

    in.close();

    /////////////////////////////////////////////////////////////////////

    std::ofstream out_bin("event.bin", std::ios::binary);

    Event e("asd", DateTime(1, 2, 3, 4, 5), DateTime(4, 5, 6, 7, 8));
    e.serialize(out_bin);

    out_bin.close();

    /////////////////////////////////////////////////////////////////////

    std::ifstream in_bin("event.bin", std::ios::binary);

    Event e1;
    e1.deserialize(in_bin);
    std::cout << e1 << std::endl;

    in_bin.close();

    return 0;
}