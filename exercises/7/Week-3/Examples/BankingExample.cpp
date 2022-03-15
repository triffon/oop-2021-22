/*
    Problem: Write a group of C++ classes that represent a person (3 names, EGN),
             a bank transaction (source IBAN, target IBAN, amount) and a bank
             account (owner - person, current amount, history of transactions,
             current amount). Implement operations for processing transactions
             on the level of the account menu.
*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const int IBAN_LENGTH = 34;

class Person
{
private:
    char *firstName;
    char *middleName;
    char *lastName;

    char egn[10];

public:
    Person(const Person &other) : Person(other.firstName, other.middleName, other.lastName, other.egn)
    {
    }

    Person(const char *firstName, const char *middleName, const char *lastName, const char egn[10])
    {
        this->firstName = new char[strlen(firstName)];
        strcpy(this->firstName, firstName);

        this->middleName = new char[strlen(middleName)];
        strcpy(this->middleName, middleName);

        this->lastName = new char[strlen(lastName)];
        strcpy(this->lastName, lastName);

        for (int i = 0; i < 10; ++i)
        {
            this->egn[i] = egn[i];
        }
    }

    ~Person()
    {
        delete[] firstName;
        delete[] middleName;
        delete[] lastName;
    }

    char *getFirstName() const
    {
        return firstName;
    }

    char *getMiddleName() const
    {
        return middleName;
    }

    char *getLastName() const
    {
        return lastName;
    }

    const char *getEGN() const
    {
        return egn;
    }
};

class Transaction
{
private:
    float amount;

    char source[IBAN_LENGTH];
    char target[IBAN_LENGTH];

public:
    Transaction(char source[IBAN_LENGTH], char target[IBAN_LENGTH], float amount)
    {
        this->amount = amount;

        for (int i = 0; i < IBAN_LENGTH; ++i)
        {
            this->source[i] = source[i];
            this->target[i] = target[i];
        }
    }

    const char *getSourceIBAN() const
    {
        return this->source;
    }

    const char *getTargetIBAN() const
    {
        return this->target;
    }

    float getAmount() const
    {
        return this->amount;
    }
};

class Account
{
private:
    Person owner;
    float balance;
    char iban[34];
    vector<Transaction> history;

public:
    Account(Person &owner, char iban[34], float balance): owner(owner)
    {
        this->balance = balance;

        for (int i = 0; i < IBAN_LENGTH; ++i)
        {
            this->iban[i] = iban[i];
        }
    }

    Person getOwner() const
    {
        return this->owner;
    }

    float getBalance() const
    {
        return this->balance;
    }

    vector<Transaction> getHistory() const
    {
        return vector<Transaction>(this->history);
    }

    void deposit(char source[34], float amount)
    {
        // TODO - check whether amount > 0
        this->balance += amount;
        this->history.push_back(Transaction(source, this->iban, amount));
    }

    void withdraw(char target[34], float amount)
    {
        // TODO - check whether we have enough money
        this->balance -= amount;
        this->history.push_back(Transaction(this->iban, target, amount));
    }
};

int main()
{
    return 0;
}