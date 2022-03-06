#include "Warrior.h"
#include <numeric>
#include <exception>
#include <iomanip>
#include <iostream>

struct Tank
{
    Warrior *mDriver = nullptr;
    unsigned short mResistance;
    unsigned short mRocketsCount;
    unsigned short mShotPower;
    unsigned short mHealth;
    unsigned short mMaxSpeed;
    bool mAlive = 1;

    bool fightWith(Tank &tank);
    void changeDriver(Warrior *warrior);
    void printInfo() const;
};

bool Tank::fightWith(Tank &tank)
{
    int sumOfPower = mRocketsCount * mShotPower - mRocketsCount * tank.mResistance;
    sumOfPower >= tank.mHealth ? tank.mAlive = false : tank.mHealth -= sumOfPower;
    return tank.mAlive;
}

void Tank::changeDriver(Warrior *warrior)
{
    if (this->mDriver != warrior)
    {
        this->mDriver = warrior;
    }
    throw std::exception();
}

void Tank::printInfo() const
{

    if (this->mDriver)
    {
        mDriver->printWarrior();
    }
    else
    {
        (std::cout << "No driver\n");
    }
    std::cout << mResistance << ' ' << mRocketsCount << ' ' << mShotPower << ' '
              << mHealth << ' ' << mMaxSpeed << ' ' << std::boolalpha << mAlive << '\n';
}