#include <iostream>

int main()
{
	// The default constructor is a constructor that does not expect any arguments
	// If there are any constructors for a class, c++ will generate a Default Constructor that does nothing
	// The default constructor is called when trying to create new object with no arguments

	/*class Account {
	private:
		std::string name;
		double balance;
	public:
		Account() {                         //  <-----   User-defined no-args contructor (default contructor and c++ will not generate a default
			name = "None";                  //           constructor
			balance = 0.0;
		}
	};*/

	/*
	class Account {
	private:
		std::string name;
		double balance;
	public:
		Account(std::string nameVal, double bal) {     // <--- no default constructor, since we defined at least one constructor c++ will not
			name = nameVal;                            // automatically create a no-arg constructor(default constructor) and if we want a
			balance = bal;							   // contructor with no args we will have to create it by ourself
		}											   // i.e calling Account frank; will cause an error because we don't have a no-arg constructor
	};
	*/

	return 0;
}
