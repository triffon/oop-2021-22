#include <iostream>
#include <fstream>

int main ()
{
    // i - intput
    // f - file
    // stream
    std::ifstream dadJokes("dadJokes.txt"); 

    if (!dadJokes.is_open()) // always check if the opening is successfull
    {
        std::cout << "Problem while opening the file" << std::endl;
        return 1;
    }

    // Reading the file word by word

    char tempWord[100];
    while (!dadJokes.eof()) // reading until end of file
    {
        dadJokes >> tempWord;
        std::cout << tempWord << std::endl;
    }

    dadJokes.close();

    return 0;
}