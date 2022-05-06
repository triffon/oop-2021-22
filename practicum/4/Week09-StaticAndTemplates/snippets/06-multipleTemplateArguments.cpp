#include <iostream>
#include <string>

template <class T, class U = int> // by default, the second argument will be 'int'
struct MyPair
{
    T first;
    U second;
};

int main ()
{
    MyPair<int, std::string> pair1 = {99, "Kireto"};
    MyPair<std::string, char> pair2 = {"Pesho", 'P'};
    MyPair<double> pair3 = {3.14, 3};
    
    return 0;
}