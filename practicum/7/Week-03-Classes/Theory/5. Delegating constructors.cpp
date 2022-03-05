#include <iostream>

class Player {
private:
	int health;
	int xp;
	bool hasUltimate;
public:
	Player();
	Player(int healthVal);
	Player(int healthVal, int xpVal, bool hasUltimateVal);
};

Player::Player(int healthVal, int xpVal, bool hasUltimateVal) : health{ healthVal }, xp{ xpVal }, hasUltimate{hasUltimateVal} {
	//...
}

Player::Player() : Player{ 0,0,0 } {
	//...
}

Player::Player(int healthVal) : Player{ healthVal, 0, 0 } {
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
