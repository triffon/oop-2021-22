#include <iostream>

const int MAX_ARR_LEN = 101;

enum class SwordType {
    SHARP, HEAVY_DAMAGE, COMPACT
};

struct Sword{
    char* mModel;
    unsigned mStrength;
    SwordType mType;
    unsigned mYearOfProduction;
};

struct Warrior{
    char* mName;
    unsigned mAge;
    Sword mSword;
};


void initializeSword(Warrior& warrior){
    warrior.mSword.mModel = new char[MAX_ARR_LEN];
    std::cin >> warrior.mSword.mModel;

    std::cin >> warrior.mSword.mStrength;

    int typeCode;

    std::cout << "Input sword type:\n";
	std::cout << "1 - SHARP\n";
	std::cout << "2 - HEAVY_DAMAGE\n";
	std::cout << "3 - COMPACT\n";
	std::cin >> typeCode;

	switch (typeCode)
	{
		case 1: warrior.mSword.mType = SwordType::SHARP; break;
		case 2: warrior.mSword.mType = SwordType::HEAVY_DAMAGE; break;
		case 3: warrior.mSword.mType = SwordType::COMPACT; break;

		default:
			std::cerr << "Not supported type!\n";
	}

    std::cin >> warrior.mSword.mYearOfProduction;
}

void initializeWarrior(Warrior& warrior){
    warrior.mName = new char[MAX_ARR_LEN];
    std::cin >> warrior.mName;

    std::cin >> warrior.mAge;

    initializeSword(warrior);
}

void printSword(const Sword& sword){
    std::cout << sword.mModel << ' ' << sword.mStrength;
    switch (sword.mType)
	{
		case SwordType::COMPACT: std::cout << "COMPACT\n"; break;
		case SwordType::HEAVY_DAMAGE: std::cout << "HEAVY_DAMAGE\n"; break;
		case SwordType::SHARP: std::cout << "SHARP\n"; break;

		default: 
		std::cout << "Nothing here.\n";
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

int main(){
    //Some tests here.

    return 0;
}