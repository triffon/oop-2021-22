#include <iostream>
#include <cstring>
#include <cassert>

struct Teacher
{
private:
    char* name;
    char* subject;

public:
    Teacher(const char* name, const char* subject)
    {
        std::cout << "Inside constuctor" << std::endl;

        this->name = new (std::nothrow) char[strlen(name) + 1];
        if (!this->name)
        {
            std::cout << "Memory problem" << std::endl;
            return;
        }
        strcpy(this->name, name);

        this->subject = new (std::nothrow) char[strlen(subject) + 1];
        if (!this->subject)
        {
            std::cout << "Memory problem" << std::endl;

            delete[] this->name; 
            return;
        }
        strcpy(this->subject, subject);
    }

    void print()
    {
        std::cout << "My name is " << this->name << " and I am teaching " << this->subject << "." << std::endl;
    }

    ~Teacher()
    {
        std::cout << "Inside destuctor" << std::endl;

        delete[] this->name;
        delete[] this->subject;
    }
};

int main ()
{
    // Teacher teacher("Borislav Draganov", "DIS2");

    // teacher.print();

    Teacher* dynamicallyAllocatedTeacher = new (std::nothrow) Teacher("Alexandra Soskova", "EAI");
    if (!dynamicallyAllocatedTeacher)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    dynamicallyAllocatedTeacher->print();
    delete dynamicallyAllocatedTeacher;

    return 0;
}