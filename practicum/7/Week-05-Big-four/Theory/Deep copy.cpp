#include <iostream>
#include <string>

class Deep {
private:
    int* data; //pointer to a integer
public:
    Deep(int d); //constructor
    Deep(const Deep& source); // copy constructor
    ~Deep(); // destructor

    void setDataValue(int d) {
        *data = d;
    }
    int getDataValue() {
        return *data;
    }
};

Deep::Deep(int d) {
    data = new int; //allocate storage
    *data = d;
}

Deep::~Deep() {
    delete data;
    std::cout << "Destructor freeing data" << std::endl; 
}

Deep::Deep(const Deep& source) {
    data = new int;
    *data = *source.data;                             // create new storage and copy values
    std::cout << "Copy constructor - deep" << std::endl;
}
//below is an alternative
Deep::Deep(const Deep& source) : Deep{ *source.data } {
    std::cout << "Copy contructor - deep copy";
}


void displayDeep(Deep s) {
    std::cout << s.getDataValue() << std::endl;  //when s goes out of scope the destructor is called and releases data.
                                                 // We have no problem since the stroage released by the destructor is unique to s
}

int main()
{
    //Deep copy is:
    /*
    - Create a copy of the pointed-to-data(with shallow we were copying only the pointer)
    - Each copy will have a pointer to unique storage in the heap
    - We use deep copy when we have a raw pointer as a class data member
    */

    Deep obj1{ 100 };
    displayDeep(obj1);

    obj1.setDataValue(1000);
    Deep obj2{ obj1 };


    return 0;
}
