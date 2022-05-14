# Polymorphism

## What is polymorphism?
- In essence, it is the ability of a single method to be applied to derived classes and achieve a proper output.
- Polymorphism types:
  - Compile-time / static-binding (before the program executes)
  - Run-time / dynamic-binding
    - Dynamic -> being able to assign different meanings to the same function at run-time
      - Achieved using virtual functions
  
```cpp
//                  Non-polymorphic example
Account a;                                                        Account
a.withdraw(1000); // Account::withdraw()                         |withdraw|
                                                                     /\
Savings b;                                                           ||   
b.withdraw(1000); // Savings::withdraw()                        --------------
                                                                |            |
Checking c;                                                 Savings      Checking
c.withdraw(1000); // Checking::withdraw()                  |withdraw|   |withdraw|
                                                               /\ 
Trust d;                                                       || 
d.withdraw(1000); // Trust::withdraw()                        Trust
                                                           |withdraw|
Account* p = new Trust();
p->withdraw(1000); // Account::withdraw()(p is pointer to Account) but should be 
                       // Trust::withdraw()
```

```cpp
//                  A polymorphic example - dynamic binding
Account a;                                                        Account
a.withdraw(1000); // Account::withdraw()                         |withdraw|
                                                                     /\
Savings b;                                                           ||
b.withdraw(1000); // Savings::withdraw()                        --------------
                                                                |            |
Checking c;                                                 Savings     Checking
c.withdraw(1000); // Checking::withdraw()                  |withdraw|   withdraw|
                                                               /\
Trust d;                                                       ||
d.withdraw(1000); // Trust::withdraw()                        Trust
                                                           |withdraw|
Account* p = new Trust();
p->withdraw(1000); // Trust::withdraw()      !!! withdraw method must be virtual in
                                                    // Account class
```

## Virtual functions
- Redefined functions are bound **statically**
- Overriden functions are bound **dynamically** (declare function virtual)
  - virtual function are overriden
  - allows us to treat all objects generally as objects of the `Base` class
  
### Declaring virtual functions
- Declare the function you want to override as **virtual** in the `Base` class
- virtual functions are virtual all the way down the hierarchy from this point
- Will be dynamically bound when using base class pointer or reference

```cpp
class Account{
public:
    virtual void withdraw(double amount);
};
```
- Once we declare the function **virtual**:
  - Override the function in the `Derived` classes
  - Function signature and return-type **MUST MATCH EXACTLY**
  - virtual keyword in the `Derived` classes is not required but is best practice
  - If you do not provide an overriden version it is inherited from it's `Base` class
```cpp
class SpecialAccount : public Account{
public:
    virtual void withdraw(double amount);
};
```

```cpp
//                                      EXAMPLE
#include <iostream>

class Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "Account::withdraw\n";
	}
};

class CheckingAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "CheckingAccount::withdraw\n";
	}
};

class SavingsAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "SavingsAccount::withdraw\n";
	}
};

class TrustAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "TrustAccount::withdraw\n";
	}
};

int main()
{
	std::cout << "Pointers:\n";
	Account* p1 = new Account();
	Account* p2 = new SavingsAccount();
	Account* p3 = new CheckingAccount();
	Account* p4 = new TrustAccount();
	/* If we did not have VIRTUAL keyword in the Account class the output is:
	p1->withdraw(1000);		Account::withdraw
	p2->withdraw(1000);		Account::withdraw
	p3->withdraw(1000);		Account::withdraw
	p4->withdraw(1000);		Account::withdraw
	*/
	p1->withdraw(1000);
	p2->withdraw(1000);
	p3->withdraw(1000);
	p4->withdraw(1000);		//We will have a warning "deleting object of polymorphic class type 'Account' see next section...
							//which has non-virtual destructor
	delete p4;
	delete p3;
	delete p2;
	delete p1;

}
```

### Virtual destructors
- As we destroy polymorphic objects problems may occur
- If a `Derived` class object is destroyed by deleting its storage via the base class pointer and the `Base` class does not have **virtual destructor**, the behaviour is undefined in the C++ context.
- Derived objects must be destroyed in the correct order starting at the correct destructor

#### Solution:
- If a class has virtual functions:
  - **ALWAYS** provide a public **virtual** destructor
  - If base class destructor is **virtual** then all derived class desturctors are also **virtual**
  - virtual keyword in the `Derived` classes is not required but is a good practice
```cpp
class Account{
public:
    virtual void withdraw(double amount);
    virtual ~Account();
};
```
```cpp
//                                  EXAMPLE
#include <iostream>

class Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "Account::withdraw\n";
	}
	virtual ~Account() { std::cout << "Account::destructor\n"; }
};

class CheckingAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "CheckingAccount::withdraw\n";
	}
	virtual ~CheckingAccount() { std::cout << "CheckingAccount::destructor\n"; }
};

class SavingsAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "SavingsAccount::withdraw\n";
	}
	virtual ~SavingsAccount() { std::cout << "SavingsAccount::destructor\n"; }
};

class TrustAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "TrustAccount::withdraw\n";
	}
	virtual ~TrustAccount() { std::cout << "TrustAccount::destructor\n"; }
};

int main()
{
	std::cout << "Pointers:\n";
	Account* p1 = new Account();
	Account* p2 = new SavingsAccount();
	Account* p3 = new CheckingAccount();
	Account* p4 = new TrustAccount();

	p1->withdraw(1000);
	p2->withdraw(1000);
	p3->withdraw(1000);
	p4->withdraw(1000);

	//in case of non-virtual destructors we will get a warning 
	//for "deleting object of polymorphic class type 'Account'
	//which has non-virtual destructor

	delete p1;			//Output: Account::destructor
	delete p2;			//Output: Account::destructor
	delete p3;			//Output: Account::destructor
	delete p4;			//Output: Account::destructor

	//if we make the Account destructor virtual => all the the Derived we will fix our problem and output is:
	//Output: Account::destructor
	//Output: CheckingAccount::destructor
	//Output: SavingsAccount::destructor
	//Output: TrustAccount::destructor

	// If we were using dynamic memory allocation in the classes and were not using virtual destructors
	// we would have memory leak because of the call only of Account::destructor
	// !! ading virtual fixes the problem :)

}
```

### Override specifier
- C++ provides an `override` specifier to have the compiler **ensure** overriding

```cpp
/*
class Base {
public:
	virtual void sayHello() const {
		std::cout << "Hello - I'm a Base class object\n";
	}
	virtual ~Base();
};

class Derived :public Base {
public:
	virtual void sayHello() { //Notice we forgot the const - NOT OVERRIDING BUT REDEFINING
		std::cout << "Hello - I'm a Derived class object\n"; //, static binding(undefined behaviour when using a base class pointer)
	}
	virtual ~Derived();
};
*/

/*int main()
{
	Base* p1 = new Base();
	p1->sayHello();			//bound dynamicly

	Base* p2 = new Derived();	//We will not get what we expected,
	p2->sayHello();				// sayHello method signatures are different
}								// So Derived redefines sayHello instead of overriding it
*/

//We can prevent this using the override specifier like:

class Base {
public:
	virtual void sayHello() const {
		std::cout << "Hello - I'm a Base class object\n";
	}
	virtual ~Base();
};

class Derived :public Base {
public:
	virtual void sayHello() const override {  // <------- When we use override the compiler will tell us
		std::cout << "Hello - I'm a Derived class object\n";// we miss something of the exact definition
	}
	virtual ~Derived();
};
```

### Final specifier
- The **final** specifier can be used in these cases:
  - When used at the class level:
    - prevents the class from being derived from
  - When used at the method level:
    - prevents virtual method from being overriden in derived classes

```cpp
class MyClass final {	//using the final specifier MyClass can't be derived from
	//...
};

class Derived : public MyClass { 

};
```

```cpp
class A {
public:
	virtual void doSomething();
};

class B : public A {
	virtual void doSomething() final;	// prevent further overriding
};

class C : public B {
	virtual void doSomething();	// COMPILER ERROR - "cannot override      
};                              //               'final'funtion B::doSomething"    
```

### Base class references
- Using `Base` class references
  - We can also use `Base` class references with dynamic polymorphism
  - useful when we pass objects to functions that expect `Base` class reference

```cpp
//                              Example
#include <iostream>

class Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "Account::withdraw\n";
	}
	virtual ~Account() { std::cout << "Account::destructor\n"; }
};

class CheckingAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "CheckingAccount::withdraw\n";
	}
	virtual ~CheckingAccount() { std::cout << "CheckingAccount::destructor\n"; }
};

class SavingsAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "SavingsAccount::withdraw\n";
	}
	virtual ~SavingsAccount() { std::cout << "SavingsAccount::destructor\n"; }
};

class TrustAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "TrustAccount::withdraw\n";
	}
	virtual ~TrustAccount() { std::cout << "TrustAccount::destructor\n"; }
};

void doWithdraw(Account& account, double amount) {
	account.withdraw(amount);
}

int main()
{
	Account a;
	Account& ref = a;
	ref.withdraw(1000); // Account::withdraw

	TrustAccount t;			// reference to an account, when called ref1.withdraw() will be bound dynamically
	Account& ref1 = t;		// because of the virtual methods
	ref1.withdraw(1000); // TrustAccount::withdraw

	Account a1;
	SavingsAccount a2;
	CheckingAccount a3;
	TrustAccount a4;
	//These methods will be bound dynamically and the output will be:
	doWithdraw(a1, 1000); // Account::withdraw
	doWithdraw(a2, 2000); // SavingsAccount::withdraw
	doWithdraw(a3, 3000); // CheckingAccount::withdraw
	doWithdraw(a4, 4000); // TrustAccount::withdraw
}
```

## Pure virutal functions and abstract classes
- What is abstract class?
  - Cannot instantiate (create) objects
  - These classes are used as `Base` classes in inheritance hierarchies
  - Often refered to as `Abstract Base classes`
- What is concrete class?
  - Used to instantiate object from
  - All their member functions are defined

### Abstract base class
- too generic to create objects from
  - Shape, Employee, Account
- Serves as parent to `Derived` classes that may have objects
- Contains at least one **pure virtual** function 

#### Pure virtual functions
- Used to make class abstract
- Specified with `= 0` in its declaration
  - `virtual void function() = 0;` -> pure virtual function
- Typically do not provide implementation of it (although it is possible)
- When we derive a class from an abstract class we **MUST override** the pure virtual function in order to make the `Derived` class a *CONCRETE* class, if that is not done then the `Derived` class is also abstract
- Use pure virtual function when the `Base` class doesn't make sense to have some functionality

## Interfaces
- An abstract class that has only **pure virtual functions**
- These functions provide general set of services to the user of the class
- provided as `public`
- Each subclass is free to implement these services as needed (in order to be concrete class)
- Every service must be implemented (function prototypes must match exactly when overriding)

```cpp
//                                    EXAMPLE
//We want to create intefece I_Printable in which we will define a print function

#include <iostream>

class I_Printable {
	friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
	virtual void print(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const I_Printable& obj) {
	obj.print(os);
	return os;
}

class Account : public I_Printable {
public:
	virtual void withdraw(double amount) {
		std::cout << "Account::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "Account print";
	}
	virtual ~Account() { std::cout << "Account::destructor\n"; }
};

class CheckingAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "CheckingAccount::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "CheckingAccount print";
	}
	virtual ~CheckingAccount() { std::cout << "CheckingAccount::destructor\n"; }
};

class SavingsAccount : public Account {	
public:
	virtual void withdraw(double amount) {
		std::cout << "SavingsAccount::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "SavingsAccount print";
	}
	virtual ~SavingsAccount() { std::cout << "SavingsAccount::destructor\n"; }
};

class TrustAccount : public Account {
public:
	virtual void withdraw(double amount) {
		std::cout << "TrustAccount::withdraw\n";
	}
	virtual void print(std::ostream& os) const override {
		os << "TrustAccount print";
	}
	virtual ~TrustAccount() { std::cout << "TrustAccount::destructor\n"; }
};

//The good point is we can do:
class Dog : public I_Printable {
public:
	virtual void print(std::ostream& os) const override {
		os << "Woof wooof";
	}
};

void print(const I_Printable& obj) {
	std::cout << obj << std::endl;
}

int main()
{
	Dog* dog = new Dog();
	print(*dog);

	Account* p1 = new Account();
	std::cout << *p1 << std::endl;

	Account* p2 = new CheckingAccount();
	std::cout << *p2 << std::endl;

	delete dog;
	delete p1;
	delete p2;
}
```