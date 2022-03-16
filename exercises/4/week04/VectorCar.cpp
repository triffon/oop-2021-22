#include "VectorCar.h"
#include <iostream>
using namespace std;
VectorCar::VectorCar(size_t capacity) {
    this->capacity = capacity;
    size = 0;
    this->vector = new Car[capacity];
}

VectorCar& VectorCar::operator=(VectorCar&& other) {

// this= other
 if (this != &other){
     cout<<"move operator ="<<endl;
     delete [] vector;
     vector = other.vector;
     size = other.size;
     capacity = other.capacity;
     other.vector = nullptr;
 }
 return *this;
}

void VectorCar::deleteObject() {
    delete [] vector;
    capacity = 0;
    size = 0;
}
void VectorCar::copyObject (const VectorCar& other) { //Copy Constructor
    vector = new Car[other.capacity];
    size = other.size; // here we have an acess up to private elements
    capacity = other.capacity;
    for (int i = 0; i < size; i++) {
        vector[i] = other.vector[i]; // in class car we should define operator=
    }
}

VectorCar& VectorCar::operator=(const VectorCar& other) {
    if (this != &other) {

        cout<<"operator ="<<endl;
        deleteObject();
        copyObject(other);
    }
    return *this;
}