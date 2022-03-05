#include <iostream>
#include <cstring>

//IMPORTANT -> initalization is done in the order which we have in the class no matter what is the order in the initialization list


/*class Player {
private:
	char* name;
	int health;
	int xp;
public:
	Player(const char* = "\0", int healthVal = 0, int xpVal = 0);  // Constructor with default values

    ~Player(){
        delete[] name;
    }
};*/

class Player {
private:
	char* name;
	int health;
	int xp;
public:
	Player(const char* nameVal = "\0", int healthVal = 0, int xpVal = 0);
	//If we write another contsructor like this:
	//Player(){} we will get a compiler error because the compiler wont be aware which contructor to take
};


Player::Player(const char* nameVal, int healthVal, int xpVal) : name(new char[strlen(nameVal) + 1]), health{ healthVal }, xp{ xpVal }{
    strcpy(name, nameVal);
}


int main()
{
	Player enemy;   // None, 0, 0
	Player frank{ "Frank" };  // Frank, 0, 0
	Player hero{ "Hero",100 }; //Hero, 100, 0
	Player villain{ "Villain", 100, 55 }; //Villain, 100, 55



	return 0;
}
