#include <cstring>

class MyString
{
private:
    char* str;
    long unsigned int mCapacity;
    void resize();
public:
    MyString(const char* str = "\0");
    MyString(const MyString& source);
    MyString& operator=(const MyString& rhs);
    ~MyString(); 

    bool empty() const;
    char& at(unsigned int pos);
    unsigned int size() const;
    unsigned int capacity() const;
    const char* c_str() const;
    void push_back(char c);
};