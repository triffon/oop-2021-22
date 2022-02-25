#include <iostream>

const int MAX_LEN = 128;
// Какво ако всеки войник вместо един меч, има масив от такива
enum SwordType
{
    SHARP,
    HEAVY_DAMAGE,
    COMPACT
};

struct Sword
{
    char *mModel;
    unsigned mStrength;
    SwordType mType;
    unsigned mYearOfProduction;
};

struct Warrior
{
    char *mName;
    unsigned mAge;
    Sword mSword;
};

void initializeSword(Warrior &warrior)
{
    warrior.mSword.mModel = new char[MAX_LEN];
    std::cin >> warrior.mSword.mModel;

    std::cin >> warrior.mSword.mStrength;

    int typeCode;

    std::cout << "Input sword type: \n";
    std::cout << "1 - SHARP\n";
    std::cout << "2 - HEAVY_DAMAGE\n";
    std::cout << "3 - COMPACT\n";

    std::cin >> typeCode;

    switch (typeCode)
    {
    case 1:
        warrior.mSword.mType = SHARP;
        break;
    case 2:
        warrior.mSword.mType = HEAVY_DAMAGE;
        break;
    case 3:
        warrior.mSword.mType = COMPACT;
        break;
    default:
        std::cerr << "Not supported type";
        break;
    }

    std::cin >> warrior.mSword.mYearOfProduction;
}

void initializeWarrior(Warrior& warrrior){
    warrrior.mName = new char[MAX_LEN];
    std::cin >> warrrior.mName;

    std::cin >> warrrior.mAge;

    initializeSword(warrrior);
}

void printSword(const Sword& sword){
    std::cout << sword.mModel << ' ' << sword.mStrength;
    switch (sword.mType)
    {
    case SHARP:
        std::cout << "Sharp\n";
        break;
    case HEAVY_DAMAGE:
        std::cout << "Heavy damage\n";
        break;
    case COMPACT:
        std::cout << "Compact\n";
        break;    
    
    default:
        std::cout << "Nothing here.\n";
        break;
    }
    std::cout << sword.mYearOfProduction;
}

void printWarrior(const Warrior& warrior){
    std::cout << warrior.mName << ' ' << warrior.mAge;
    printSword(warrior.mSword);
}

void killWarrior(Warrior& warrior){
    delete[] warrior.mName;
    delete[] warrior.mSword.mModel;
}

int main()
{
    Warrior w;
    initializeWarrior(w);

    printWarrior(w);

    killWarrior(w);
}
