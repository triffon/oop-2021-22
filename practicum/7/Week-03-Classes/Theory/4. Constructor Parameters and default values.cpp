#include <iostream>

/*class Player {
private:
	std::string name;
	int health;
	int xp;
public:
	Player(std::string nameVal = "None", int healthVal = 0, int xpVal = 0);  // Constructor with default values
};*/

class Player {
private:
	std::string name;
	int health;
	int xp;
public:
	Player(std::string nameVal = "None", int healthVal = 0, int xpVal = 0);
	//If we write another contsructor like this:
	//Player(){} we will get a compiler error because the compiler wont be aware which contructor to take
};


Player::Player(std::string nameVal, int healthVal, int xpVal) : name{ nameVal }, health{ healthVal }, xp{ xpVal }{

}


int main()
{
	Player enemy;   // None, 0, 0
	Player frank{ "Frank" };  // Frank, 0, 0
	Player hero{ "Hero",100 }; //Hero, 100, 0
	Player villain{ "Villain", 100, 55 }; //Villain, 100, 55

    

	return 0;
}
