#include <iostream>

// If we want to have cstring, we would need to allocate the memory in the constructor and then strcpy any info in it using strcpy
//IMPORTANT -> initalization is done in the order which we have in the class no matter what is the order in the initialization list


class Player {
private:
    int health;
    int xp;
public:
    Player();
    Player(int healthVal);
    Player(int healthVal, int xpVal);
};

/*
Player::Player() {          //Previous way(old)         
    health = 0;             // ASSIGNMENT NOT INITIALIZATION
    xp = 0;
}
*/

Player::Player() : health{ 0 }, xp{ 0 } {   
    //...
}
Player::Player(int healthVal) : health { healthVal }, xp { 0 } {
    //...
}
Player::Player(int healthVal, int xpVal) : health{ healthVal }, xp{ xpVal } {
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
