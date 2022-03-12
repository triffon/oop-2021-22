#include <iostream>
#include <assert.h>
using namespace std;

class StackInt {
private:
    int *arr;
    size_t size;
    size_t capacity;
    void deleteObject() {
        delete [] arr;
        capacity = 0;
        size = 0;
    }
    void copyObject (const StackInt& other) { //Copy Constructor
        arr = new int[other.capacity];
        size = other.size; // here we have an acess up to private elements
        capacity = other.capacity;
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
public:
    StackInt() { // Constructor
        capacity = 10;
        this->arr = new int[capacity]; // What about error handling? (std::nothrow)
        size = 0;
    }

    StackInt(const StackInt& other) { //Copy Constructor
        copyObject(other);
    }
    //operator= ?
    // operator>
    // operator== bool
    // operator!= = !(operator==)
    StackInt& operator=(const StackInt& other) {
        if (this != &other) {
            deleteObject();
            copyObject(other);
        }
        return *this;
    }
    ~StackInt() {
        deleteObject();
    }


    bool push(int el) { // This should be bool or void?
        if (size == capacity) {
            int *newArray = new (std::nothrow) int [capacity * 2]; // Error handling?
            // later...
            if (newArray != nullptr) {
                for (int i = 0; i < size; i++) {
                    newArray[i] = arr[i];
                }
                delete [] arr;
                arr = newArray;
                newArray = nullptr; // Do we need this one?
            } else {
                return false;
            }
        }
        arr[size++] = el;
        return true;
    }

    void pop() {
        //if (size == 0) {return;}//?
        assert(size != 0);
        size--;
    }
    int front () {
        assert(size != 0);
        return arr[size-1];
    }

};
// = > < [...] <= != ...
int main() {
      StackInt s;
      s.push(1);
//    s.push(2);
//    StackInt s2;
//    s2 = s;
    StackInt s2(s);
    int a;
    cout<<(a = 5)<<endl;
    return 0;
}
