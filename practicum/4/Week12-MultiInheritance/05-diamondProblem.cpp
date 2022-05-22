#include <iostream>
#include <string>

class Base
{
private:
    std::string name;

public:
    Base()
    {
        std::cout << "Base()::Base()" << std::endl;
    }

    ~Base()
    {
        std::cout << "Base()::~Base()" << std::endl;
    }
};

class Derived1 : virtual public Base
{
private:
    int age;

public:
    Derived1()
    {
        std::cout << "Derived1()::Derived1()" << std::endl;
    }

    ~Derived1()
    {
        std::cout << "Derived1()::~Derived1()" << std::endl;
    }
};


class Derived2 : virtual public Base
{
private:
    char letter;

public:
    Derived2()
    {
        std::cout << "Derived2()::Derived2()" << std::endl;
    }

    ~Derived2()
    {
        std::cout << "Derived2()::~Derived2()" << std::endl;
    }
};

class ThirdLevel : public Derived1, public Derived2
{
public:
    ThirdLevel()
    {
        std::cout << "ThirdLevel()::ThirdLevel()" << std::endl;
    }

    ~ThirdLevel()
    {
        std::cout << "ThirdLevel()::~ThirdLevel()" << std::endl;
    }
};