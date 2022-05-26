#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>

class Component
{
private:
    std::string label;


public:
    Component(const std::string& label) : label(label) {}

    virtual double price() const = 0;

    virtual void output(std::ostream& out) const
    {
        out << label << " " << this->price();
    }

    virtual ~Component() = default; 
};

class CPU : public Component
{
private:
    unsigned short cores;
    unsigned short clockSpeed;

public:
    CPU(const std::string& label, unsigned short cores, unsigned short clockSpeed)
        : Component(label)
    {
        assert(cores >= 1 && cores <= 8);

        this->cores = cores;
        this->clockSpeed = clockSpeed;
    }

    virtual double price() const override
    {
        return 29.99 * this->cores;
    }
};

class Memory : public Component
{
private:
    unsigned short capacity;

public:
    Memory(const std::string& label, unsigned short capacity)
        : Component(label)
    {

        assert(capacity >= 1 && capacity <= 10000);

        this->capacity = capacity;
    }

    virtual double price() const override
    {
        return 89.99 * this->capacity;
    }
};

Component* create_component()
{
    int option = -1;
    std::cout << "What type of component do you want to create?" << std::endl;
    std::cout << "1. CPU" << std::endl;
    std::cout << "2. Memory" << std::endl;

    std::cin >> option;

    if (option == 1)
    {
        unsigned short cores, clockSpeed;
        std::string label;
        std::cout << "Enter label: ";
        std::cin >> label;
        std::cout << "Enter cores: ";
        std::cin >> cores;
        std::cout << "Enter clock speed: ";
        std::cin >> clockSpeed;

        return new CPU(label, cores, clockSpeed);
    }
    else if (option == 2)
    {
        unsigned short capacity;
        std::string label;
        std::cout << "Enter label: ";
        std::cin >> label;
        std::cout << "Enter capacity: ";
        std::cin >> capacity;

        return new Memory(label, capacity);
    }
    
    return nullptr;
}

class Configuration
{
private:
    std::vector<const Component*> components;

    Configuration() = default;

    void insert(const Component* c)
    {
        for (std::size_t i = 0; i < components.size(); ++i)
        {
            if (typeid(*c) == typeid(*components[i]))
            {
                throw std::invalid_argument("Element of this type already exists");
            }
        }

        this->components.push_back(c);
    }

public:
    Configuration(const Configuration& other) = delete;
    Configuration& operator = (const Configuration& other) = delete;

    double price() const
    {
        double sum = 0;
        for (std::size_t i = 0; i < components.size(); ++i)
        {
            sum += this->components[i]->price();
        }

        return sum;
    }

    std::size_t size() const
    {
        return this->components.size();
    }

    const Component& operator [] (std::size_t index) const
    {
        assert (index < this->components.size());

        return *this->components[index];
    }

    friend std::ostream& operator << (std::ostream& out, const Configuration& configuration)
    {
        for (std::size_t i = 0; i < configuration.components.size(); ++i)
        {
            configuration.components[i]->output(out);
            out << std::endl;
        }

        out << configuration.price();

        return out;
    }

    ~Configuration()
    {
        for (std::size_t i = 0; i < components.size(); ++i)
        {
            delete this->components[i];
        }
    }

    friend Configuration* create_configuration();
    
};

Configuration* create_configuration()
{
        Configuration* configuration = new (std::nothrow) Configuration();
        if (!configuration)
        {
            return nullptr;
        }

        std::cout << "How many components do you want to add to your configururation?" << std::endl;
        std::size_t count;
        std::cin >> count;

        for (std::size_t i = 0; i < count; ++i)
        {
            configuration->insert(create_component());
        }

        return configuration;
}

int main()
{
    Configuration* config = create_configuration();

    std::cout << *config;

    std::string path;
    std::cout << "Enter file path: ";
    std::cin >> path;

    std::ofstream os(path);

    if(!os.is_open())
    {
        return 1;
    }

    os << *config;

    os.close();

    return 0;
}