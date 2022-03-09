#include "Tank.h"

const int maxParkingCapacity = 1000;

struct MilitaryParking
{
    short mCurrentCount = 0;
    Tank mTanks[maxParkingCapacity];

    unsigned int sumOfTanksPower() const;
    void prettyPrint() const;
    bool strongerThan(const MilitaryParking& other);
    const Tank& nthTank(int n) const;
    int fightWith(MilitaryParking& opponent);
};

void MilitaryParking::prettyPrint() const{
    for (int i = 0; i < mCurrentCount; i++)
    {
        mTanks[i].printInfo();
    }
}

unsigned int MilitaryParking::sumOfTanksPower() const{
    unsigned int sum = 0;
    for (int i = 0; i < mCurrentCount; i++)
    {
        sum += mTanks[i].mShotPower;
    }
    return sum;
}

bool MilitaryParking::strongerThan(const MilitaryParking &other){
    return this->sumOfTanksPower() >= other.sumOfTanksPower();
}

const Tank &MilitaryParking::nthTank(int n) const{
    if(n > mCurrentCount){
        throw std::invalid_argument("Not valid position");
    }
    return mTanks[n];
}

int MilitaryParking::fightWith(MilitaryParking &opponent){
    if(this != &opponent){
        throw std::invalid_argument("Cant fight with yourself");
    }
    
    int casualties = 0;
    for (int i = 0; i < (mCurrentCount > opponent.mCurrentCount) ? opponent.mCurrentCount : mCurrentCount; i++)
    {
        this->mTanks[i].fightWith(opponent.mTanks[i]); //here we will destroy the opponnet tank
        casualties += opponent.mTanks[i].fightWith(mTanks[i]); //here we will destroy our tank
        // Тъй като не е ясно дефинирано допускаме, че танковете се бият i-ти с i-ти, дори опонента да е убит.

    }
    return casualties;
}