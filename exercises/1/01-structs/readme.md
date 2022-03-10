# Structs

## Definition

Aggregated data type that allow us to group multiple variables of mixed types together

## Syntax

```c++
/*
struct <name>
{
  <type_1> <var_1>;
  <type_2> <var_2>;
  ...  
};
*/

struct test
{
    int a;
    double b;
    int c;
};

// Groups 2 ints and a double together
```

## Access

Access members through the operator .

```c++
test x;
x.a = 10;
x.b = 2.0;
/// ...
```

## Access through pointer

Instead of dereferencing pointers to structs we could use the operator -> as shorthand

```c++
test x;
test * y = &x;

(*y).a = 10; // BAD
y->a = 10; // GOOD

// ^ These 2 are equivalent
```

## Non-static Member initialization

We could give default values to the various members

```c++
struct default_test
{
    int a{10};
    double b{3.14};
    int c{20};
};
```

```c++
test x; // No default values
std::cout << x.a << ' ' << x.b << ' ' << x.c << '\n'; // Undefined Behavior. x.a x.b and x.c haven't been initialized

default_test xx;
std::cout << xx.a << ' ' << xx.b << ' ' << xx.c << '\n'; // 10 3.14 20
```

## Uniform Initialization

Initialize structs with {}

```c++
default_test x{1, 2.3, 4};
std::cout << x.a << ' ' << x.b << ' ' << x.c; // 1 2.3 4

// You could initialize just some of the members. The rest will be default initialized

default_test partial_x{1, 2.3}; // x.a = 1, x.b = 2.3, x.c = 20
default_test partial_y{1}; // x.a = 1, x.b = 3.14, x.c = 20
default_test partial_z{}; // Equivalent to default_test partial_z; 
```

## Size

Some rules:
- Empty (trivial) structs are 1 byte (0 byte means they can't have unique adresses and that's illegal)
- Every member starts at a position, divisible by it's align (see std::alignof, for primitive types its same as size)
- The size is divisible by the size of its largest member

The last 2 are for CPU optimizations

```c++
// Assuming sizeof(int) = 4 and sizeof(double) = 8

struct test_size
{
    int a; // 4
    double b; // 8
    int c; // 4
};

// 4 + 8 + 4 = 16 BUT
std::cout << sizeof(test_size); // 24

/*
    Why does that happen?

    First of all alignof(double) = 8 => double cannot start directly after the int (we need 4 bytes of padding) (16 + 4 = 20)
    Secondly, the size of the struct must be divisible by 8 (sizeof(double)) => 24 is the smallest number bigger than 20 and divisible by 8 so we add 4 more bytes of padding at the end

    The struct would look like this
    |4 bytes int|4 bytes padding|8 bytes double|4 bytes int|4 bytes padding|
    for a total of 24 bytes
*/

// Smaller version of the same struct

struct smaller_test
{
    int a; // 4
    int c; // 4
    double b; // 8
};

std::cout << sizeof(smaller_test); // 16 !!!!

/*
    How did that happen?
    alignof(int) is 4 so it has no problem starting directly after the first int at position 4.
    Struct so far: |4 bytes int|4 bytes int|
    alingof(double) is 8, again no problem starting at position 8
    Struct so far: |4 bytes int|4 bytes int|8 bytes double|
    16 is divisible by 8 (sizeof(double)) so we don't need padding at the end
*/
```

## Relevant Guidelines

- [Organize related data into structrues](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-org)
- [Use struct if the data members can vary independently](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-struct)

More about rule #2 next time.
