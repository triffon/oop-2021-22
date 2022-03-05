#include <iostream>

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    Player();
    Player(std::string nameVal);
    Player(std::string nameVald, int healthVal, int xpVal);
};

Player::Player() {
    name = "None";
}

Player::Player(std::string nameVal) {
    name = nameVal;
    health = 0;
    xp = 0;
}

Player::Player(std::string nameVal, int healthVal, int xpVal) {
    name = nameVal;
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
