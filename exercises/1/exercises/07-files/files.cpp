#include <iostream>
#include <fstream>
#include <ios>

using std::ios;

/*
a -> A
A -> a
1 -> 1
*/

const int letter_diff{'a' - 'A'};


char change_letter_capitalization(char c)
{
    if ( c >= 'a' && c <= 'z')
    {
        return c - letter_diff;
    }
    
    if (c >= 'A' && c <= 'Z')
    {
        return c + letter_diff;
    }

    return c;
}

void change_capitalization(std::fstream& file)
{
    char c{};
    while (file)
    {
        file.get(c);
        file.seekg(-1, std::ios::cur);
        file.put(change_letter_capitalization(c));
    }
}

int main()
{
    std::fstream file{
        "file.txt",
        ios::in | ios::out
    };

    change_capitalization(file);

    // Duma 2ra Duma malka duma GOLQMA DUMA

    return 0;
}