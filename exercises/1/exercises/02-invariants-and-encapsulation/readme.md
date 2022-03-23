# Encapsulation and Class Invariants

## Cliffnotes

- P.O.D
- Invariants (assert)
- Encapsulation (public vs private)
- class keyword
- Member functions (hidden *this* pointer, const qualifier)
- Constructors (default, order, initializer list)
- Chaining Methods
- Explicit Constructors

## Guidelines (that actually double up as notes)

- [Use ```class``` if the type has an invariant](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c2-use-class-if-the-class-has-an-invariant-use-struct-if-the-data-members-can-vary-independently)

- [Make functions members only if they need direct access to the representation](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c4-make-a-function-a-member-only-if-it-needs-direct-access-to-the-representation-of-a-class)

- [Don't define a class and declare a variable of its type in the same statement](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-standalone)

- [Use ```class``` if any member is non-public](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-class)

- [Minimize exposure](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-private)

- [Make member functions const by default](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rconst-fct)

- [Define a ctor if a class has an invariant](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-ctor)

- [A ctor should create a fully initialized object](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-complete)

- [Ensure that copyable classes have default ctors](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-default0)

- [Prefer simple default ctors](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-default00)

- [Use in-class member initialization instead of default ctors that don't do anything else](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-default)

- [Declare single-argument ctors explicit by default](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-explicit)

- [Initialize member variables in order of declaration](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-order)

- [Prefer in-class initializers for constant initializers](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-in-class-initializer)

- [Prefer initialization to assignment in ctors](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-initialize)

- [Reuse ctors for common actions (didn't fully cover in class)](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-delegating)


## Small Problem

Implement the following classes

### Employee

The employees have the following properties

- Name with no more than 50 characters
- Age between 18 and 64
- Monthly salary between 610 and 10000
- Relevant constructors, selectors and mutators
- A method that prints all information about the employee

### Company

With the following properties

- Up to 1000 employees
- Relevant constructors, selectors and mutators
- A method that checks if the company is empty
- A method that adds an employee to the company
- A method that fires an employee with given name from the company and returns false if he doesn't exist (remove only first one with given name)
- A method that sorts the employees in the company by name
- A method that gives the total monthly salary of all employees
- A method that raises the salary of an employee with a given name by a given percentage
- A method that prints the information about all employees
