#include <string>
#include <iostream>
#include <cstring>

int main(){
    std::string str;
    str = "Hello world";
    std::cout << str << '\n';

    str.push_back('!');
    std::cout << str;
    str.pop_back();
    std::cout << str;
}

