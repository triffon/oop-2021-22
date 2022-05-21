#include<iostream>
using namespace std;

class A {
public:
    A() {cout<<"A"<<endl;}
    A(int a) {cout<<"A()"<<endl;}
     void sayHello () {cout<<"Hello World";}
};

class B : virtual public A {
public:
    B() : A(6) {cout<<"B"<<endl;}
    void sayHello () {cout<<"Hello World B";}

};

class C : virtual public A {
public:
    C() : A(6){cout<<"C"<<endl;}

    void sayHello () {cout<<"Hello World C";}
};

class D : public C, public B {
public:  D()  {cout<<"D"<<endl;}
    void sayHello () {
        B::sayHello();
        cout<<endl;
        (B(*this)).sayHello();
        cout<<endl;
    }
    void sayHelloD() {
    A::sayHello();
    cout<<endl;
    //(A(*this)).sayHello();
    cout<<endl;
    }

};
/**
 *
 * int *a = new int[1000];
 * a[0] = 1;
 **/
int main()  {
//    exit(0);
//    cout<<"asd"<<endl;
//    return 0;
    D *d = new D();
    d->sayHello();
    d->sayHelloD();
//D d();
//d.sayHello();
}