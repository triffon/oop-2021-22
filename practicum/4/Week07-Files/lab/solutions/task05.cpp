#include <iostream>
#include <fstream>
#include <cstring>

class Pokemon
{
private:
    char name[50];
    int power;

public:
    Pokemon(const char* name = "", const int power = 10)
    {
        strcpy(this->name, name);
        this->power = power;
    }
};

class PokemonHandler
{
private:
    char fileName[50];

    int getFileSize()
    {
        std::ifstream file(fileName);

        if (!file)
        {
            return -1;
        }

        // std::size_t currentPos = file.tellg();
        file.seekg(0, std::ios::end);
        std::size_t resultPos = file.tellg();
        // file.seekg(currentPos);

        return resultPos - 0;
    }

public:
    /**
     * @brief Construct a new PokemonHandler object
     * 
     * @param fileName a binary file name where the info about the Pokemons will be saved
     * @param pokemons an array of Pokemons
     * @param size size of the array of Pokemons
     */
    PokemonHandler(const char* fileName, Pokemon* pokemons, std::size_t size)
    {
        strcpy(this->fileName, fileName);

        std::ofstream file(fileName, std::ios::binary);

        if (!file.is_open())
        {
            return;
        }

        for (std::size_t i = 0; i < size; ++i)
        {
            file.write(reinterpret_cast<const char*>(&pokemons[i]), sizeof(Pokemon));
        }

        file.close();
    }

    Pokemon operator [] (std::size_t index)
    {
        Pokemon result;

        int pokemonCount = this->getFileSize() / sizeof(Pokemon);

        if (index >= pokemonCount)
        {
            return Pokemon();
        }

        std::ifstream file(this->fileName);

        if (!file.is_open())
        {
            return Pokemon();
        }

        file.seekg(index * sizeof(Pokemon), std::ios::beg);

        file.read((char*)(&result), sizeof(Pokemon));

        file.close();

        return result;
    }
};

int main ()
{
    return 0;
}