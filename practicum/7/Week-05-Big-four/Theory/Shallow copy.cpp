#include <iostream>

//Shallow copy
class Shallow {
private:
    int* data; //pointer to an integer
public:
    void setDataValue(int d) {
        *data = d;
    }
    int getDataValue() {
        return *data;
    }

    Shallow(int d); //contructor
    Shallow(const Shallow& source); //copy contstructor

    ~Shallow(); //destructor
};

Shallow::Shallow(int d) {
    data = new int; //allocate storage
    *data = d;
}

Shallow::~Shallow() {
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}

Shallow::Shallow(const Shallow& source) : data{ source.data } {  //Shallow copy - only the pointer is copied - not what it is pointing to
    std::cout << "Copy contructor - shallow" << std::endl; //Problem : source and the newly created object BOTH point to the SAME data area!
}

void displayShallow(Shallow s) {
    std::cout << s.getDataValue();
}


int main()
{
    Shallow obj1{ 100 };
    displayShallow(obj1);

    Shallow obj2{ obj1 };
    obj2.setDataValue(1000);

    return 0;
}
