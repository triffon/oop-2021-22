#include "money.h"

int main()
{
    Money money1(2, 60), money2(3, 50);

    money2.print();
    money2 -= money1;
    money2.print();

    Money money3 = Money(2, 80) - Money(1, 10);
    money3.print();
    
    return 0;
}