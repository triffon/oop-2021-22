#include "money.h"

int main()
{
    Money money1(2, 60);

    Money money2 = money1 + 3;
    money2.print();

    Money money3 = 5 + money1;
    money3.print();
    
    return 0;
}