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

bool VectorCar::operator==(const VectorCar& other) {
    if (this == &other) return true;
    if (size != other.size) return false;
    if (capacity != other.capacity) return false; //? do we need this one?
    for (int i =0;i<size;i++) {
        if (vector[i] != other.vector[i]) return false;
    }

    return true;
}

VectorCar VectorCar::operator+(const VectorCar& other) {
    VectorCar newVectorCar = *this;
    for (int i =0;i <other.size;i++) {
        bool originalElement = true;
        for (int t = 0;t<size;t++) {
            if (newVectorCar.vector[i] == other.vector[t]) {
                originalElement = false;
                break;
            }
        }
        if (originalElement) {
            newVectorCar += other.vector[i];
           // other.vector[i] += newVectorCar; this is not yet implemented
        }
    }
    return newVectorCar;
}

VectorCar& VectorCar::operator+=(const VectorCar& other) {
     // *this = *this + other; Slow solution
    for (int i =0;i <other.size;i++) {
        bool originalElement = true;
        for (int t = 0;t<size;t++) {
            if (vector[i] == other.vector[t]) {
                originalElement = false;
                break;
            }
        }
        if (originalElement) {
            *this += other.vector[i];
            // other.vector[i] += newVectorCar; this is not yet implemented
        }
    }

    return *this;

}

VectorCar::VectorCar(const VectorCar& car) {
    copyObject(car);
}


VectorCar& VectorCar::operator+=(const Car& other) {
    if (size == capacity) {} // TBD resize;
    vector[size++] = other; //car = car;
    return *this;
}