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
 * */
#include <iostream>
#include <string>
// #include <VectorCars> not in g++ namespace
#include "VectorCar.h"
using namespace std;

struct LinkedList {
    int key; // 4bytes
    //LinkedList next; // ?
    LinkedList* next; //1byte
};

void print(string stringParam) {
    cout<<stringParam<<endl;
}

void print1(const string& stringParam) {
    cout<<stringParam<<endl;
}

void print2(string& stringParam) {
    cout<< "lvalue ";
    cout<<stringParam<<endl;
}

void print2(string&& stringParam) {
    cout<< "rvalue ";
    cout<<stringParam<<endl;
}

int main () {
string s = "asdasd";
string s1 = "Hello ";
//print(s);
//print(s + s1); // Hello asdasd
print2(s1); // Hello
print2(s + s1); //
// lvalue = rvalue

VectorCar test(10);
// test is lvalue
VectorCar test1;

test1 = test;
VectorCar test2;
test2 = std::move(test); // now test will be handled as a rvalue


return 0;
}