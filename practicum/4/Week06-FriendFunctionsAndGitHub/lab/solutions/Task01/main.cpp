#include <iostream>
#include "Time.h"

int main ()
{
    Time t1(2, 40), t2(3, 30), t3, t4, t5;

    std::cout << (t1 + t2);

    t3 = t1 + t2;
    std::cout << t3;

    t4 = t1 + 5;
    std::cout << t4;

    t5 = 6 + t1;
    std::cout << t5;
    
    std::cout << std::boolalpha << (t1 > t2) << std::endl;

    return 0;
}