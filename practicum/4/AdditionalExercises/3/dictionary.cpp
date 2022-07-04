#include <iostream>
#include <string>

template <typename K, typename V>
class Dictionary
{
private:
    static const std::size_t INITIAL_CAPACITY = 4;
    static const std::size_t INCREASE_STEP = 2;

    std::size_t size;
    std::size_t capacity;
    K* keys;
    V* values;

    void deallocate()
    {
        delete[] this->keys;
        delete[] this->values;

        this->keys = nullptr;
        this->values = nullptr;
    }

    void copy(const Dictionary<K, V>& other)
    {
        this->keys = new K[other.capacity];
        try
        {
            this->values = new V[other.capacity];
        }
        catch(const std::bad_alloc& ba)
        {
            delete[] this->keys;
            throw ba;
        }
        
        for (std::size_t i = 0; i < other.size; ++i)
        {
            try
            {
                this->keys[i] = other.keys[i];
                this->values[i] = other.values[i];
            }
            catch(const std::exception& e)
            {
                this->deallocate();
                throw e;
            }
        }

        this->size = other.size;
        this->capacity = other.capacity;
    }

    int contains(const K& key) const
    {
        for (std::size_t i = 0; i < this->size; ++i)
        {
            if (key == this->keys[i])
            {
                return i;
            }
        }

        return -1;
    }

    void resize()
    {
        K* newKeys = new K[this->capacity * INCREASE_STEP];
        V* newValues = nullptr;

        try
        {
            newValues = new V[this->capacity * INCREASE_STEP];
        }
        catch(const std::bad_alloc& ba)
        {
            delete[] newKeys;
            throw ba;
        }

        for (std::size_t i = 0; i < this->size; ++i)
        {
            try
            {
                newKeys[i] = this->keys[i];
                newValues[i] = this->values[i];
            }
            catch(const std::exception& e)
            {
                delete[] newKeys;
                delete[] newValues;
                throw e;
            }
        }

        this->capacity *= INCREASE_STEP;
        this->deallocate();
        this->keys = newKeys;
        this->values = newValues;
    }

public:
    Dictionary()
    {
        this->size = 0;
        this->capacity = INITIAL_CAPACITY;

        this->keys = new K[this->capacity];

        try
        {
            this->values = new V[this->capacity];
        }
        catch(const std::bad_alloc& ba)
        {
            delete[] this->keys;
            throw ba;
        }
    }

    Dictionary(const Dictionary<K,V>& other)
    {
        this->copy(other);
    }

    Dictionary& operator = (const Dictionary<K,V>& other)
    {
        if (this != &other)
        {
            this->deallocate();
            this->copy(other);
        }

        return *this;
    }

    ~Dictionary()
    {
        this->deallocate();
    }

    template <typename A, typename B>
    friend std::ostream& operator << (std::ostream& out, const Dictionary<A,B>& dictionary)
    {
        out << "Size: " << dictionary.size << std::endl;
        out << "Capacity: " << dictionary.capacity << std::endl;

        for (std::size_t i = 0; i < dictionary.size; ++i)
        {
            out << dictionary.keys[i] << " " << dictionary.values[i] << std::endl;
        }

        return out;
    }

    void add(const K& key, const V& value)
    {
        if (this->contains(key) != -1)
        {
            return;
        }

        if (this->size == this->capacity)
        {
            this->resize();
        }

        // try/catch
        this->keys[this->size] = key;
        this->values[this->size] = value; 

        ++this->size;
    }

    V& operator [] (const K& key)
    {
        int index = this->contains(key);

        if (index == -1)
        {
            throw std::invalid_argument("No such key");
        }

        return this->values[index];
    }

    const V& operator [] (const K& key) const
    {
        int index = this->contains(key);

        if (index == -1)
        {
            throw std::invalid_argument("No such key");
        }

        return this->values[index];
    }

    void printSorted() const
    {
        Dictionary<K, V> copyDict = *this;

        for (int i = 0; i < copyDict.size; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < copyDict.size; ++j)
            {
                if (copyDict.keys[j] < copyDict.keys[minIndex])
                {
                    minIndex = j;
                }
            }

            std::swap(copyDict.keys[i], copyDict.keys[minIndex]);
            std::swap(copyDict.values[i], copyDict.values[minIndex]);
        }

        std::cout << copyDict;
    }    
};

int main ()
{
    Dictionary<int, std::string> dictionary;
    dictionary.add(5, "Pe60");
    dictionary.add(3, "Silve");
    dictionary.add(2, "Teo");
    dictionary.add(7, "Kiara");
    dictionary.add(10, "Mimeee");

    dictionary.printSorted();

    return 0;
}