#include <iostream>
#include <cstring>
#include <cmath>

class Walker
{
protected:
    double averageSpeed;

private:
    char* description;

    void deallocate()
    {
        delete[] this->description;
    }

    void copy(const Walker& other)
    {
        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);

        this->averageSpeed = other.averageSpeed;
    }

public:
    Walker(const char* description = "", double averageSpeed = 0)
    {
        this->description = new char[strlen(description) + 1];
        strcpy(this->description, description);

        this->averageSpeed = averageSpeed;
    }

    Walker(const Walker& other)
    {
        this->copy(other);
    }

    Walker& operator = (const Walker& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    virtual ~Walker()
    {
        this->deallocate();
    }

    virtual double walk(double distance)
    {
        return distance / this->averageSpeed;
    }

    virtual Walker* clone() const
    {
        // return new Walker(this->description, this->averageSpeed);
        return new Walker(*this);
    }
};

class Vehicle : public Walker
{
private:
    double amortisation;

public:
    Vehicle(const char* description = "", double averageSpeed = 0, double amortisation = 0)
        : Walker(description, averageSpeed), amortisation(amortisation)
    {}

    Vehicle(const Vehicle& other) : Walker(other)
    {
        this->amortisation = other.amortisation;
    }

    Vehicle& operator = (const Vehicle& other)
    {
        if (this != &other)
        {
            Walker::operator=(other);
            this->amortisation = other.amortisation;
        }

        return *this;
    }

    virtual ~Vehicle() = default;

    virtual double walk(double distance) override final
    {
        amortisation += distance;

        double currentAverageSpeed = Walker::averageSpeed - std::floor(amortisation / 100);

        return std::max(currentAverageSpeed, Walker::averageSpeed / 2);
    }

    virtual Walker* clone() const override final
    {
        return new Vehicle(*this); 
    }
};

class Fleet
{
private:
    static const std::size_t MAX_CAPACITY = 15;

    Walker* arr[MAX_CAPACITY];
    std::size_t size;

    void copy(const Fleet& other)
    {
        for (std::size_t i = 0; i < other.size; ++i)
        {
            this->arr[i] = other.arr[i]->clone();
        }

        this->size = other.size;
    }

    void deallocate()
    {
        for (std::size_t i = 0; i < this->size; ++i)
        {
            delete this->arr[i];
        }
    }

public:
    Fleet() : size(0) {}

    Fleet(const Fleet& other)
    {
        this->copy(other);
    }

    Fleet& operator = (const Fleet& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    void addWalker(const Walker* ptr)
    {
        if (this->size == MAX_CAPACITY)
        {
            throw std::overflow_error("4A6ATA PRELQ!!!");
        }

        this->arr[this->size++] = ptr->clone();
    }

    double walkAll(double distance)
    {
        double sum = 0.0;

        for (std::size_t i = 0; i < this->size; ++i)
        {
            sum += this->arr[i]->walk(distance);
        }

        return sum / this->size;
    }
};

int main ()
{

}   