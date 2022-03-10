#include <iostream>
#include <cstring>

class Player {
private:
    char* name;
    int health;
    int xp;
public:
    Player();
    Player(const char* nameVal); // we can unite the default constructor and this one using default param "\0";
    Player(const char* nameVal, int healthVal, int xpVal);
};

Player::Player() {
    name = new char[1];
    strcpy(name, "\0");
}

Player::Player(const char* nameVal) {
    name = new char[strlen(nameVal) + 1]; //this can be allocated in the initialization list.
    strncpy(name, nameVal, strlen(nameVal) + 1);
    health = 0;
    xp = 0;
}

Player::Player(const char* nameVal, int healthVal, int xpVal) {
    name = new char[strlen(nameVal) + 1]; //this can be allocated in the initialization list.
    strncpy(name, nameVal, strlen(nameVal) + 1);
    health = healthVal;
    xp = xpVal;
}

int main()
{
    /*
    - Classes can have as much constructors as needed
    - Each must have a unique signature
    - Default constructor is no longer compiler-generated once another constructor is declared
    */
    Player empty; // None, 0, 0

    Player hero("Hero");
    Player hero = { "Hero" }; // Hero, 0, 0
    Player hero{ "Hero" };
    
    Player frank = { "Frank", 100, 4 }; // Frank, 100, 4

    Player* enemy = new Player("Enemy", 1000, 0); // Enemy, 1000, 0
    delete enemy;

    return 0;
}
