#include <iostream>
#include <fstream>

int main (int agrc, char** argv)
{
    if (agrc == 2)
    {
        std::ifstream file(argv[1], std::ios::binary);

        if (!file.is_open())
        {
            return 1;
        }

        file.seekg(0, std::ios::end);
        std::size_t size = file.tellg();

        std::cout << size << std::endl;

        file.close();
    }

    return 0;
}