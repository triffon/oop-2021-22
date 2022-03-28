# Encapsulation and Class Invariants

## Cliffnotes

- RAII
- Destructors
- Rule of 3
- Copy Constructor and Copy Assignment
- Rule of 0
- Vector data structure

## Possibly

- rvalues
- move semantics
- move cosntructor and move assignment
- Rule of 5

## Definitions

### Resource Acquisition Is Initialization (RAII)

Holding a resource is a class invariant and is tied to the object's lifetime. **R**esource **A**cquisition **I**s done at **I**nitialization while deallocation is done at destruction (hence the dumb name). This guarantees that we hold the resource during and only during the object's lifetime.

- [Manage resources automatically using RAII](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#r1-manage-resources-automatically-using-resource-handles-and-raii-resource-acquisition-is-initialization)

### Rule of 3

If your class defines or deletes any of:
- Destructor
- Copy Constructor
- Copy Assignment Operator

It should probably define all 3 to guarantee **correctness**.

### Rule of 5

If you define and/or delete any of the above methods OR you define/delete any of
- Move Constructor
- Move Assignment Operator

You should probably define all 5 to guarantee **performance**.

- [If you define or ```=delete``` any default operation, define or ```=delete``` them all](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c21-if-you-define-or-delete-any-default-operation-define-or-delete-them-all)

### Rule of 0

If your class does not **directly** deal with ownership it probably doesn't need custom special functions.

- [Avoid defining default operations when possible](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c20-if-you-can-avoid-defining-default-operations-do)

- Business Logic classes should not deal directly with resources and should follow the rule of 0.
- Resource management classes should follow the rule of 5.

### Special Functions and Default Behaviour

- Default Constructor ```X()```
- Copy Constructor ```X(const X&)```
- Copy Assignment Operator ```X& operator=(const X&)```
- Destructor ```~X()```
- Move Constructor ```X(X&&)```
- Move Assignment Operator ```X& operator=(X&&)```

By default the compiler generates simple special operations that treat the class like a value type by calling the special operation of each member in the class.

#### Example

```c++
class Value
{
public:
	int x;
};

// The compiler will generate a correct copy constructor that behaves sort of like this.
/*
	Value(const Value& other)
	{
		x = other.x;
	}
*/

class Owner
{
public:
	int* ptr;
};

// The compiler will generate a likely incorrect copy constructor that behaves in the same way
/*
	Owner(const Owner& other)
	{
		ptr = other.ptr
	}
*/
// Note that this doesn't copy the object pointerd by ptr so now the 2 Onwers "own" 2 non-independent values
```

## Guidelines

- [Use RAII to prevent leaks](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#e6-use-raii-to-prevent-leaks)
- [Make default operations consistent](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c22-make-default-operations-consistent)
- [Ask yourself if your class needs a destructor](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#cdtor-destructors)
- [Define a destructor if a class needs to do something at object destruction](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c30-define-a-destructor-if-a-class-needs-an-explicit-action-at-object-destruction)
- [Release all owned resources in the dtor](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c31-all-resources-acquired-by-a-class-must-be-released-by-the-classs-destructor)
- [If a class owns a resource define a dtor](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c33-if-a-class-has-an-owning-pointer-member-define-a-destructor)
- [A copy operation should create an independant copy](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c61-a-copy-operation-should-copy)
- [Make copy assignment safe for self-assignment](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c62-make-copy-assignment-safe-for-self-assignment)
- [Use ```=default``` if you want to be explicit about using default implementations](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c80-use-default-if-you-have-to-be-explicit-about-using-the-default-semantics)
- [Use ```=delete``` to supress default behaviour without providing an alternative](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c81-use-delete-when-you-want-to-disable-default-behavior-without-wanting-an-alternative)
- [Provide a swap function for value types](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c83-for-value-like-types-consider-providing-a-noexcept-swap-function)
- [Follow the STL when defining a container (more on that later)](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rcon-stl)
- [Give containers value semantics](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c101-give-a-container-value-semantics)
- [Give containers default ctors that set them to empty](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c101-give-a-container-value-semantics)
