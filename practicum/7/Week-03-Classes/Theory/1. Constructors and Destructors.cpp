#include <iostream>
#include <cstring>

int main()
{
	//constructors
	/*
	- invoked during object creation
	- useful for initialization
	- same name as the class
	- no return type specified
	- can be overloaded
	*/

	/*
	class Player {
	private:
		int health;
		int xp;
	public:
		//overloaded constructors
		Player();
		Player(int health);
		Player(int health, int xp);
	};
	*/

	//destructors
	/*
	- same name as the class but with ~ (~ class name)
	- invoked automatically when object is destroyed
	- no return type and no parameters
	- only 1 destructor per class !!! can't be overloaded !!!
	- useful to release memory and other resources
	*/
	/*
	class Player {
	private:
		char* name;
		int health;
		int xp;
	public:
		//overloaded constructors
		Player();
		Player(char* name);
		Player(char* name, int health, int xp);

		//destructor (CANT BE OVERLOADED)
		~Player();
	};
	*/

	class Player {
	private:
		char* name;
		int health;
		int xp;
	public:
		void setName(const char* nameVal) {
			strcpy(name, nameVal);
		}
		//constructors
		Player() {
			std::cout << "No args constructor called";
		}
		Player(const char* name) {
			std::cout << "String argumented constructor called";
		}
		Player(const char* name, int health, int xp) {
			std::cout << "Three argumented constructor called";
		}
		// destructor (CANT BE OVERLOADED)
		~Player() {
			std::cout << "Destructor called for " << name;
			delete[] name;
		}
	};


	{
		Player slayer;  //No args constructor called
		
		slayer.setName("Slayer"); //Destructor called for "Slayer"
	}

	{
		Player frank; //No args constructor called
		frank.setName("Frank");
		Player hero("Hero"); //String argumented constructor called
		hero.setName("Hero");
		Player villain("Villain", 100, 12); //Three argumented constructor called
		villain.setName("Villain");
		//the order of destruction is the reverse of the creation (Villain(destroyed first) -> Hero -> Frank(destroyed last))
	}
	//Player test = {"Test", 100, 12};
	//Player test("Test", 100, 12);


	Player* enemy = new Player; //No args constructor called
	enemy->setName("Enemy"); // set name to Enemy

	Player* levelBoss = new Player("Level Boss", 1000, 300); //Three argumented constructor called
	levelBoss->setName("Level Boss"); // set name to Level Boss

	delete enemy; //enemy destructor called
	delete levelBoss; //level boss destructor called


	return 0;
}