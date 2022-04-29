# OOP Part

## What is inheritance?
- Method of creating new classes from existing classes (Reuse mechanism)
- The new class contains data and behaviours of the existing class
- Types of inheritance:
  - Single -> new class is created from another `single` class
  - Multiple -> new class is created from two(or more) other classes

## Basic terminology:
- Base class (parent class)
  - The class being extended or inherited from
- Derived class (child class)
  - The class being created from the `Base` class
  - Inherits attributes and operations from `Base` class
- `Is-A` relationship (a `circle` IS A `shape`)
- Generalization:
  - combining similar classes into a single, more general class based on common attributes
- Specialization:
  - creating new classes from existing classes providing more specialized attributes
- Class Hierarchy:
  - Organization of our inheritance relationships
  - Example:
```
Classes:									generalization		/A/				||
	- A	(route class)								/\				/\			||
	- B is derived from A	(! b is not a C)		||		 -------||-------	||
	- C is derived from A							||		 |				|	||
	- D is derived from C							||		/B/			   /C/	||
	- E is derived from D (E is also a D,C,A)		||					   /\	||
	(deriving is transitive)						||					   ||	||
													||					   /D/	||
													||					   /\	||
													||					   ||	\/
													||					   /E/	specialization
```

## Inheritance vs Composition
- Both allow reuse of existing classes
- Inheritance:
  - `is-a` relationship:
    - `Employee` is-a `Person`
    - `Circle` is-a `Shape`
- Composition:
  - `has-a` relationship:
    - `Person` has-a `BankAccount`
    - `Player` has-a `SpecialAttack`

## Deriving from Existing classes
- Access modifiers:
  - public
  - private
  - protected
```cpp
class Base{
    //Base class members 
}

class Derived{ //: access-specifier BaseClass
    //Derived class members
}
```

```cpp
class Account {
    //Account class members...
};
class SavingAccount : public Account {
    //SavingsAccount class members...
};
//SavingsAccount 'is-a' Account
```
```cpp
//Lets give an example of different derivations:
class X{
public:        
    int public;    // In the case of public inheritance: in derived class -> a-public,
                    // b-protected, c-no access
protected:
    int protected;  // In the case of protected...: in derived class -> a-protected, 
                    //b-protected, c-noaccess
private:
    int private;    // In the case of private...: in derived class -> a-private,
                    // b-private, c-noaccess
}
```

## Constructors and Destructors
- Constructors and class initialization:
  - A `derived` class inherits from its `Base` class
  - The `Base` class **MUST** be initialized **BEFORE** the `Derived` class is initialized
  - When a `Derived` object is created:
    - `Base` class constructor executes then
    - `Derived` class constructor executes
- Destructors:
  - Class destructors are invoked in the reverse order of constructors
  - The `Derived` part of the `Derived` class **MUST** be destroyed **BEFORE** the `Base` class destructor is called
    - Each destructor should free resources allocated in it's own constructors

### Derived class does NOT inherit:
- Base class constructors
- Base class destructor
- Base class overloaded operators
- Base class friend functions
  - However the `Derived` class constructor, destructor, overloaded operators & friends can invoke the `Base` class versions

### Passing args to Base class ctor-s
- Passing arguments to `Base` class constructors
  - The Base part of a Derived class must be initialized first
```cpp
Q: How can we control exactly which Base class constructor is used during initialization?
A: We can invoke whichever Base class constructor we wish in the initialization list of the Derived class.
```

```cpp
class Base {
public:
	Base();
	Base(int);
};
Derived::Derived(int x) : Base(x) {
		
}
```

```cpp
class Base {
private:
	int value;
public:
	Base() : value{ 0 } { std::cout << "Base default constructor called\n"; }
	Base(int x) : value{ x } { std::cout << "Base (int) constructor called\n"; }
	~Base() { std::cout << "Base destructor called\n"; }
};

class Derived : public Base {
private:
	int doubledValue;
public:
	Derived() : Base{ 0 }, doubledValue { 0 } { std::cout << "Derived default constructor called\n"; }
	Derived(int x) : Base{ x }, doubledValue{ 2*x } { std::cout << "Derived (int) constructor called\n"; }
	~Derived() { std::cout << "Derived destructor called\n"; }
};
```

### Copy, Move, Operators
- Not inherited from the `Base` class
- Often you do not need to provide your own
  - If you DO NOT define them in `Derived` then the compiler will create them automatically and call the base class's version
  - If you DO provide `Derived` versions then YOU MUST invoke the `Base` versions EXPLICITLY yourself
- **Be careful** with **RAW Pointers**
  - Especially if `Base` and `Derived` each have raw pointers
  - Provide them with *deep copy semantics*

```cpp
#include <iostream>

class Base {
private:
	int value;
public:
	Base() : value{ 0 } { std::cout << "Base no-args constructor called\n"; }
	Base(int x) : value{ x } { std::cout << "Base (int) constructor called\n"; }
	Base(const Base& other) : value{other.value} { std::cout << "Base copy constructor called\n"; }
	Base& operator=(const Base& rhs) {
		std::cout << "Base operator= called\n";
		if (this != &rhs) {
			value = rhs.value;
		}
		return *this;
	}
	~Base() { std::cout << "Base destructor called\n"; }
};

class Derived : public Base {
private:
	int doubledValue;
public:
	Derived() : Base{} { std::cout << "Derived no-args constructor called\n"; }
	Derived(int x) : Base{x} { std::cout << "Derived (int) constructor called\n"; }
	Derived(const Derived& other) : Base{ other }, doubledValue{ other.doubledValue } {
		std::cout << "Derived copy constructor called\n";
	}

	Derived& operator=(const Derived& rhs) {
		std::cout << "Derived operator= called\n";
		if (this != &rhs) {
			Base::operator=(rhs);
			doubledValue = rhs.doubledValue;
		}
		return *this;
	}

	~Derived() { std::cout << "Derived destructor called\n"; }
};

int main() {
	Base b{ 100 }; //Overloaded constructor
	Base b1{ b }; //Copy constructor
	b = b1;		//Copy assignment

	Derived d{ 100 };	//Overloaded constructor
	Derived d1{ d1 };  //Copy constructor
	d = d1;			  //Copy assignment
}
```

```cpp
#include <iostream>
//                                      MOVE SEMANTICS EXAMPLE
class MyString {
private:
	char* str;
public:
	//... constructors
	MyString(MyString&& rhs) : str{ rhs.str } {
		rhs.str = nullptr;
	}
	MyString& operator=(MyString&& rhs)
	{
		if (this != &rhs) {  //check for self assignment

		    delete[] this->str;  //deallocate storage for this->str since we are overwriting it
		    str = rhs.str;		 //steal the pointer from the rhs object and assign it to this->str
		    rhs.str = nullptr;   //null out the rhs pointer
        }
		return *this;		 //return the current object by reference to allow chain assignment
	}
};

class Text : public MyString {
private:
	char* biggerStr;
public:
	//consturctors
	Text(Text&& rhs) : MyString(std::move(rhs)), biggerStr(rhs.biggerStr) {
		rhs.biggerStr = nullptr;
	}
	
	Text& operator=(Text&& rhs) {
		if (this != &rhs) {
			MyString::operator=(std::move(rhs));
			delete[] biggerStr;
			biggerStr = rhs.biggerStr;
			rhs.biggerStr = nullptr;
		}
        return *this;
	}
};
```

## Redefining Base class methods (overriding)
- `Derived` class can directly **INVOKE** `Base` class methods
- `Derived` class can **OVERRIDE** or **REDEFINE** `Base` class methods (very powerful when using polymorphic functions *will see that later through the semester*)
- Pseudo-example:
```cpp
class Account {
public:
    void deposit(double amount) { balance += amount; }
};
    
class SavingsAccount : public Account {
public:
    void deposit(double amount) {  //REDEFINE Base class method
        amount += interest;
        Account::deposit(amount);  //INVOKE call Base class method
    }
};
```

### Static binding of method calls
- The compiler determines which is method is called based on what it "sees" compile-time
  - Default binding in C++ is **static** (more efficient)
  - Derived class objects will use `Derived::deposit`
  - We can explicitly invoke `Base::deposit` from `Derived::deposit` which is fine in most cases but limited, much more powerful is **dynamic** binding (runtime) (*will see that in the polymorphism part*)

```cpp
//                                      Example
Base b;
b.deposit(1000.0);  // Base::deposit

Derived d;
d.deposit(100.0);   // Derived::deposit

Base* ptr = new Derived();
ptr->deposit(1000.0);   // The compiler will call Base::deposit         
                        // because it sees *pointer-to-BaseClass*,to fix this we will need Dynamic Binding 
```