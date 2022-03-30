/* Реалицирайте структура Car, която да съдържа
 * име/модел на кола
 * година на производство
 * цена
 * Да се иплмементиран необходимите get-ъри и set-ъри, както и необходимите данни от вида rule of 0/3/5
 * Да се имплемевтира динамичен масив, тип контейнер вектор за тип Car
 * Да се имплементира към него необходимите rule of 0/3/5
 * Да се имплементира добавяне, изтриване и търсене на кола по цена, година на произвосто или име
 * Да се имплементират operator== който да сравнява дали в две колекции, всички коли съвпадат по позиция и тип
 * Да се имплементира operator+ за обединяване на 2 колекции. В една колекция не се оаква да имаме повтарящ се елемнт.
 * Да се имплементира operator- за изваждане на една колекция от друга
 * Да се имплементират operator[] във възможните му състояния.
 * Да се имплементират оператори за вход и изход за VectorCar
 * Да се имплементират префиксен и постфиксен оператор за Car ++
 * */
#include <iostream>
#include <string>
// #include <VectorCars> not in g++ namespace
#include "VectorCar.h"
using namespace std;

bool operator==(int year,const Car& other) {
    return year == other.year;
}
int operator+(int year,const Car& other) {
    return year + other.year;
}

ostream& operator<<(ostream& out, const Car& other) {
    out<<other.name<< " "<< other.year<<endl;
    return cout;
}

istream& operator>>(istream& in, Car& other) {
    char a[100];

    in>> a >> other.year;
    delete [] other.name;
    other.name = new char[strlen(a)+1]; // Error handling
    strcpy(other.name, a);
    return in;
}

struct temp {
    int a;
    friend ostream& operator<<( ostream&, const temp& );
private:
    int b;
};
ostream& operator<<( ostream& out, const temp& other) {
    out<<other.a<< " "<< other.b<<endl;
    return cout;
}

// STDIN - 0
// STDOUT - 1
// error - 2
// =, == > <= >=,  << >>, ++
// !, ++
int main () {
    VectorCar a(23);
    a[0] = Car("BMW", 1998);
    cout<<a[0]<<endl;
    const Car newCar = a[0];
    cout<< newCar<<endl;
    Car  car ("BMW", 2019);
    cin>>car;
    cout << car<<endl;


//1010
//    //(5>>1)
//int asd = 1;
//cout<<asd++<<endl; //?
//cout<<asd<<endl;
//cout<<++asd<<endl;
////method --> this == a?
// a == this?


//Car car;
//
//int a[1000];
//
//    v[0] = Car(); // One
//    const Car v1 = v[0];
// //a[3] = 3; *(a+3) = 3;
//return 0;
}

/**
 * class A { int a, b; T operator+ (const B&)}
 * class B { int c, d;}
 *
 * */
 // A + B ==? B + A
 // B + A;
 //friend