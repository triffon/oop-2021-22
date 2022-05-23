#pragma once
template <typename T>
class Array {
  protected:
    T *arr;
    int size;
    int capacity;

    void copy(const Array<T> &other) {
        erase();
        this->setArray(other.arr, other.size);
        this->setCapacity(other.capacity); //
    }

    void erase() {
        if (this->arr != nullptr) {
            delete[] this->arr;
            this->arr = nullptr;
        }
    }

    void resize() {
        int newCap = capacity * 2;
        T *newArr = new T[newCap];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCap;
    }

  public:
    Array<T>(int capacity = 1) {
        this->size = 0;
        this->capacity = capacity;
        this->arr = new T[this->capacity];
    }

    void add(T const &element) {
        if (this->size == this->capacity) {
            this->resize();
        }
        this->arr[this->size++] = element;
    }

    int getSize() const {
        return this->size;
    }

    void setSize(int other) {
        this->size = other;
    }

    int getCapacity() const {
        return this->capacity;
    }

    void setCapacity(int other) {
        this->capacity = other;
    }

    const T *getArray() const {
        return this->arr;
    }

    void setArray(T *other, int size) {
        erase();
        this->arr = new T[size];
        for (int i = 0; i < size; i++) {
            this->arr[i] = other[i];
        }
        this->capacity = size;
        this->size = size;
    }

    Array<T>(Array<T> const &other) : Array<T>() {
        copy(other);
    }

    Array<T> &operator=(Array<T> const &other) {
        if (this != &other)
            copy(other);
        return *this;
    }

    ~Array<T>() {
        erase();
    }

    void map(T (*func)(const T &)) {
        for (int i = 0; i < this->size; i++) {
            arr[i] = func(arr[i]);
        }
    }

    T foldl(T nv, T (*op)(const T &, const T &)) {
        for (int i = 0; i < this->size; i++) {
            nv = op(nv, arr[i]);
        }
        return nv;
    }

    Array<T> filter(bool (*pred)(const T &)) {
        Array<T> ans;

        for (int i = 0; i < this->size; i++) {

            if (pred(arr[i])) {
                ans.add(arr[i]);
            }
        }

        return ans;
    }
};
