#include <iostream>

int main()
{
    /*
    - Copy assignment operator (=)
      - C++ provides a default assignment operator used ofr assigning one object to another
        Mystring s1 {"Frank"};
        Mystring s2 = s1;       //NOT assignment because its the same as Mystring s2{s1}; (initialization statement)
        ,but:
        s2 = s1     ASSIGNMENT
    
    - Default is memberwise assignment (shallow copy)
      - if we have a raw pointer data member we must deep copy
    */

    return 0;
}
