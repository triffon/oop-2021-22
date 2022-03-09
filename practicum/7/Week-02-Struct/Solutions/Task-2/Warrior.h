
enum Rank{
    MAJOR, SERGEANT, OFFICER, OTHER
};

enum Country{
    BULGARIA, RUSSIA, UKRAINE, OTHER
};

struct Warrior
{
    Rank mRank;
    Country mCountry;
    short mHeight;
    short mAge;

    void printWarrior() const;
};


void Warrior::printWarrior() const{
    //cout the enums the way we know
    std::cout << mHeight << ' ' << mAge << '\n';
}


