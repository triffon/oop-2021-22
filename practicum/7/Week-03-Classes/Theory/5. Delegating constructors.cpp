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

Player::Player(std::string nameVal, int healthVal, int xpVal) : name{nameVal}, health{ healthVal }, xp{ xpVal } {
	//...
}

Player::Player() : Player{ "None",0,0 } {
	//...
}

Player::Player(std::string nameVal) : Player{ nameVal, 0, 0 } {
	//...
}


int main()
{
	/*
	- Code for one constructor can call another in the initialization list
	- avoids duplicating code
	*/

	
	return 0;

}
