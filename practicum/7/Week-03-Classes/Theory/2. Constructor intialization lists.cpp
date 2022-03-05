#include <iostream>

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    Player();
    Player(std::string nameVal);
    Player(std::string nameVal, int healthVal, int xpVal);
};

/*
Player::Player() {          //Previous way(old)
    name = "None";          
    health = 0;             // ASSIGNMENT NOT INITIALIZATION
    xp = 0;
}
*/

Player::Player() : name{ "None" }, health{ 0 }, xp{ 0 } {   
    //...
}
Player::Player(std::string nameVal) : name { nameVal }, health { 0 }, xp { 0 } {
    //...
}
Player::Player(std::string nameVal, int healthVal, int xpVal) : name{ nameVal }, health{ healthVal }, xp{ xpVal } {
    //...
}

int main()
{
    /*
    - So far, all data member values have been set in the constructor body
    - Constructor initialization lists:
      - are more efficient
      - initialization list immediately follows the parameter list
      - initializes the data members as the object is created
      - order of intialization is the order of decalration in the class
    */

    // check top of project for the example      /\
    //                                           ||
    return 0;
}
