#include <iostream>
#include <cstring>
#include <exception>

const int maxStrLen = 80;
const int maxTranctionsCount = 100;
const int maxAccountsCount = 1000;

enum TransactionsSummaryType{
    POSITIVE, NEGATIVE, ALL
};

enum Country{
    AUSTRIA, BULGARIA, CZECH_REPUBLIC, RUSSIA, UKRAINE, CHINA, OTHER
};

struct Owner
{
    char mName[maxStrLen];
    char mSurname[maxStrLen];
    short mAge;
    Country mCountry;
};

struct BankAccount
{
    Owner mOwner;
    long long int mBalance = 0;
    int mTranctionsCurrCount = 0;
    long long int mTransactions[maxTranctionsCount];
};

struct BankSystem
{
    int mAccountsCurrCount = 0;
    BankAccount mAccounts[maxAccountsCount];
};

bool areOwnersEqual(const Owner& lhs, const Owner& rhs){
    return (lhs.mAge == rhs.mAge && lhs.mCountry == rhs.mCountry
    && strcmp(lhs.mName, rhs.mName) == 0 && strcmp(lhs.mSurname, rhs.mSurname) == 0);
}

// int ownerAccountCount(const Owner& owner, const BankSystem& system){
//     int counter = 0;
//     for (int i = 0; i < system.mAccountsCurrCount; i++)
//     {
//         if(areOwnersEqual(system.mAccounts[i].mOwner, owner)){
//             counter++;
//         }
//     }
//     return counter;
// }

void printBalance(const Owner& owner, const BankSystem& system){
    long long int sum = 0;  // we are not guaranteed that the result will fit in here
    bool found = 0;
    for (int i = 0; i < system.mAccountsCurrCount; i++)
    {
        if(areOwnersEqual(owner,system.mAccounts[i].mOwner)){
            sum += system.mAccounts[i].mBalance;
            std::cout << system.mAccounts[i].mBalance << ' ';
            found = true;
        }
    }
    if(!found){
        throw std::exception();
    }
    std::cout << "And net worth is" << sum;
}

const BankAccount& getNthAccount(const Owner& owner, const BankSystem& system, int n){
    if(n >= system.mAccountsCurrCount){
        throw std::exception();
    }

    int tempCounter = 0;
    for (int i = 0; i < system.mAccountsCurrCount; i++)
    {
        if(areOwnersEqual(owner,system.mAccounts[i].mOwner)){
            tempCounter++;
            if(tempCounter == n){
                return system.mAccounts[i];
            }
        }
    }
    throw std::exception();   
}

void printTransactions(const Owner& owner, const BankSystem& system, int x, TransactionsSummaryType type){
    const BankAccount& acc = getNthAccount(owner,system,x);
    for(int i = 0; i < acc.mTranctionsCurrCount; i++){
        if(type == POSITIVE && acc.mTransactions[i] >= 0){
            std::cout << acc.mTransactions[i];
        }
        else if(type == NEGATIVE && acc.mTransactions[i] < 0){
            std::cout << acc.mTransactions[i];
        }
        else{
            std::cout << acc.mTransactions[i];
        }
    }
}

int main(){
    // Owner x;
    // x.mAge = 18;
    // x.mCountry = BULGARIA;
    // strcpy(x.mName, "Georgi");
    // strcpy(x.mSurname, "Bogatiq");

    // Owner y = x;

}