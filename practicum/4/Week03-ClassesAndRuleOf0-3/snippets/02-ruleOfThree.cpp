#include <iostream>
#include <cstring>
#include <cassert>

const std::size_t MAX_COLOR_SIZE = 100;

struct Baloon
{
private:
    double price;
    char* color;

    void copy(const Baloon& other)
    {
        this->color = new (std::nothrow) char[strlen(other.color) + 1];
        if (!this->color)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }
        strcpy(this->color, other.color);

        this->price = other.price;
    }

    void deallocate()
    {
        delete[] this->color;
    }

public:
    Baloon()
    {
        this->price = 0.0;
        this->color = nullptr;
    }

    Baloon(const double price, const char* color)
    {
        assert(color != nullptr);

        this->price = price;

        this->color = new (std::nothrow) char[strlen(color) + 1];
        if (!this->color)
        {
            std::cout << "Memory problem!" << std::endl;
            this->price = 0.0;
            return;
        }
        
        strcpy(this->color, color);
    }

    void readFromConsole()
    {
        std::cout << "Enter price: ";
        std::cin >> this->price;
        std::cin.ignore();

        char buffer[MAX_COLOR_SIZE];
        std::cout << "Enter color: ";
        std::cin.getline(buffer, MAX_COLOR_SIZE);

        this->color = new (std::nothrow) char[strlen(buffer) + 1];
        if (!this->color)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }
        strcpy(this->color, buffer);
    }

    void print()
    {
        assert(this->color != nullptr);

        std::cout << "I am a baloon, my color is " << this->color << " and my price is " << this->price << std::endl; 
    }

    double getPrice() const
    {
        return this->price;
    }

    const char* getColor() const
    {
        return this->color;
    }

    void setPrice(const double price)
    {
        this->price = price;
    }

    void setColor(const char* color)
    {
        assert(color != nullptr);

        delete[] this->color;
        this->color = new (std::nothrow) char[strlen(color) + 1];
        if (!this->color)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }

        strcpy(this->color, color);
    }

    ~Baloon()
    {
        this->deallocate();
    }

    Baloon(const Baloon& other) // copy constructor
    {
        std::cout << "Inside copy constructor" << std::endl;

        this->copy(other);
    }

    Baloon& operator = (const Baloon& other) // copy assignment operator
    {
        std::cout << "Inside operator =" << std::endl;

        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }
};

// RULE OF 3 - Copy constructor, Copy assignment operator and Destructor
// You should implement them if you work with dynamic memory

int main ()
{
    int a = 5;

    int copyA;
    copyA = a;

    a = 6;

    std::cout << a << " " << copyA << std::endl;


    Baloon red(10, "red");

    Baloon copyAssignementRed;
    copyAssignementRed = red;

    red.setColor("more red");

    red.print();
    copyAssignementRed.print();

    Baloon copyConstructorRed(red);
    copyConstructorRed.print();

    Baloon mysteriousRed = red;
    mysteriousRed.print();

    return 0;
}