#include "money.h"

int main()
{
    Money money1(2, 60), money2(3, 50);

    money1.print();
    money1 += money2;
    money1.print();

    Money money3 = money1 + money2;
    money3.print();
    
    return 0;
}