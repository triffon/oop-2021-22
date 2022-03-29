//
// Created by Свилен on 15/03/2022.
//

#ifndef WEEK04_VECTORCAR_H
#define WEEK04_VECTORCAR_H

// Rule of 0 - we dont have any dynamic memory
// We could use out of the box  copy constructor, destructor and operator=

// Rule of 3 - we have  dynamic memory
// We could use out of the box copy constructor, destructor and operator=

// Rule of 5 - we have dynamic memory
// We could use out of the box copy constructor, destructor and operator=
// move constructor and move operator=
#include <string.h>
#include <iostream>
using namespace  std;
struct Car {
    char* name;
    int year;
    Car(char* name, int year) {
        this->name = new char[strlen(name)+1]; // error handling? \0
        strcpy(this->name, name);
        this->year = year;
    }
    Car() {
        this->name = nullptr; // error handling? \0
        this->year = 0;
    }

    Car& operator=(const Car& other) {
        if (this != &other) {
            delete [] name;
            this->name = new char[strlen(other.name)+1]; // error handling? \0
            strcpy(this->name, other.name);
            this->year = year;
        }
        return *this;
    }

    bool operator==(const Car& other) const {
        if (this == &other) return true;
        if (year == other.year && strcmp(name, other.name) == 0) return true;
        return false;
    }

    bool operator==(int year) const {
         if (year == this->year) return true;
        return false;
    }

    bool operator!=(const Car& other) const {
        return !(*this == other);
    }

};

#include <iostream>
class VectorCar {
    Car* vector;
    size_t capacity;
    size_t size;
    void deleteObject();
    void copyObject(const VectorCar& other);
public:
    VectorCar(const VectorCar& car);
    VectorCar(size_t capacity = 4);
    bool operator==(const VectorCar& other);
    VectorCar& operator=(const VectorCar& other);
    VectorCar operator+(const VectorCar& other);
    VectorCar& operator+=(const Car& other);
    VectorCar& operator+=(const VectorCar& other);
    VectorCar& operator=(VectorCar&& other); // const VectorCar&
    Car& operator[] (size_t);
    const Car operator[](size_t) const;
            // this is rvalue
            // 1) Delete of this
            // 2) copy of the dynamic memory from rvalue
            // 3).... rvalue will be deleted?

};


#endif //WEEK04_VECTORCAR_H
