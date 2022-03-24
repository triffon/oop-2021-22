#include <iostream>

class Test {
private:
	int val;
public:
	int getVal() const;
};

int Test::getVal() const {
	return val;
}

int main()
{
	/* Using const with classes:
	* Pass arguments to class member methods as const
	* We can also create const objects
	* What happens if we call member functions on const objects?? (HINT: ERROR)
	* const-correctness
	*/

	/*
	const Player villain {"Villain", 100, 55};  (villain is a const object so its attributes cannot change)
	
	void displayPlayerName(const Player& p){
		std::cout << p.getVal() << endl;
	}
	displayPlayerName(villain);   //there will be an error because the compiler is not sure if getVal does not change something ERROR



	THE SOLUTION IS: tell the compiler we won't modify the object adding "const" in ending of member functions
	std::string getVal() const;
	*/

	return 0;
}
