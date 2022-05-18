#include<iostream>
using namespace std;

class A {
protected: int z;
public:
    int *arr;
    int x;
    A() {cout<<"A"<<endl; arr = new int [100];}
    ~A() {cout<<"~A"<<endl; delete [] arr;}
    A(int test) : x(test) {cout<<"Test"<<endl; arr = new int [test]; }
    void sayHello () {cout<<"Hello A"<<endl;}
};

//class C {
//public:
//    C() {cout<<"C"<<endl;}
//    ~C() {cout<<"~C"<<endl;}
//};

class B : public A {
public:
    int y;
    B() {cout<<"B"<<endl;}
    ~B() {cout<<"~B"<<endl; /*delete [] arr*/;}
    B(int x, int y) : A(x) {
       // arr = new int [100];
        cout<<"Constructor with params..."<<endl;
        //this->x = x;
        this->y = y;
    }
    int getProtectedValue () {
        return this->z;
    }
    void sayHello () {
        A::sayHello();
        cout<<"Hello B"<<endl;
    }
};

int main () {

    A *test = new A;
    // test->z; z if protected so no access from here...
    delete test;
    B *testB = new B(3,4);
    // A --> B
    // testB -> arr;
    testB->sayHello();
    delete testB;
    return 0;
}