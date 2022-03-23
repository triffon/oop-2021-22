#include <iostream>
#include <cstring>

int main()
{
	/*
	- We use copy constructor in order to create a new object from an existing object
	- We need a copy of an object when:
	 - passing object by value as a parameter
	 - returning an object from a function by value
	- C++ provides a compiler-defined copy constructor if we don't
	*/

	// Examples of when using copy-constructor is needed
	//Player hero { "Hero", 100, 20 };

	/* 1.Pass object by value
	void displayPlayer(Player p){
		// p is a copy  of hero in this example
		// use p
		// Destructor for p will be called because p exist
	}
	*/
	//displayPlayer(hero);

	/* 2. Return object by value
	Player enemy;

	Player createSuperEnemy(){
		Player anEnemy{"Super enemy", 1000, 1000};
		return anEnemy;
	}
	*/
	//enemy = anEnemy; copy of an enemy is made

	/* 3. Construc one object based on another
	Player hero {"Hero", 100, 100};
	Player anotherHero {hero}; !!!   A copy of hero is made    !!!
	*/

	// NB If we have a pointer data member: 1. the pointer will be copied    2. Not what it is pointing to

	//Declaring the Copy constructor:

	//Type::Type(const Type & source);  //prototype of copy construct

	/*
	Player::Player(const Player & source) : name{ source.name }, health{ source.health }, xp{ source.xp } {

	}*/
	//            ------------------------------------------------------------------------------------------------------
	// Code examples:





	return 0;
}

class Player {
private:
	char* name;
	int health;
	int xp;
public:
	const char* getName() { return name; }
	int getHealth() { return health; }
	int getXp() { return xp; }

	Player(const char* nameVal = "\0", int healthVal = 0, int xpVal = 0);

	Player(const Player& source); //prototype of copy constructor

	//testing the lifecycle of this object so we create a default destructor
	~Player() {
		std::cout << "Destructor called for: " << name << std::endl;
	}
};

Player::Player(const Player& source) : name{ new char[strlen(source.name) + 1] }, health{ source.health }, xp{ source.xp } {
	strcpy(name, source.name);
}

void displayPlayer(Player p) {
	std::cout << "Name: " << p.getName() << std::endl;
	std::cout << "Health: " << p.getHealth() << std::endl;
	std::cout << "Xp: " << p.getXp() << std::endl;
}

Player::Player(const char* nameVal, int healthVal, int xpVal) : name{ new char[strlen(nameVal) + 1] }, health{ healthVal }, xp{ xpVal } {
	strcpy(name,nameVal);
    // std::cout << "Three-args contructor for " << name << std::endl;
}
