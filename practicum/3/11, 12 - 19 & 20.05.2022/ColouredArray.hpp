#pragma once
#include "Array.hpp"

// Недовършено

template <typename T, typename C>
class ColouredArray : public Array<T> {
    C *colour;

    void erase() {
        if (this->colour != nullptr) {
            delete[] this->colour;
            this->colour = nullptr;
        }
        Array<T>::erase();
    }

    void copy(ColouredArray<T, C> const &other) {
        this->erase();
        this->colour = new C[other.capacity];
        for (int i = 0; i < other.size; i++) {
            this->colour[i] = other.colour[i];
        }

        Array<T>::copy(other);
    }

    void resize() {
        Array<T>::resize();
        C *newColArr = new C[this->capacity];
        for (int i = 0; i < this->size; i++) {
            newColArr[i] = this->colour[i];
        }
        delete[] colour;
        colour = newColArr;
    }

  public:
    ColouredArray<T, C>(int capacity = 1) : Array<T>(capacity) {
        this->colour = new C[capacity];
    }

    ColouredArray<T, C>(ColouredArray<T, C> const &other) : Array<T>(other) {
        this->copy(other);
    }

    ColouredArray<T, C> &operator=(ColouredArray<T, C> const &other) {
        if (this != &other) {
            erase();
            copy(other);
        }
        return *this;
    }

    ~ColouredArray<T, C>() {
        this->erase();
    }

    const C *getColour() const {
        return this->colour;
    }

    void setArray(T *values, C *colour, int size) {
        Array<T>::setArray(values, size);
        if (this->colour != nullptr)
            delete[] this->colour;
        this->colour = new C[size];
        for (int i = 0; i < size; i++) {
            this->colour[i] = colour[i];
        }
    }
};
