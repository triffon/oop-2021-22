#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Animals {
    int h,w,age;
    string type;
protected:
    int getAge() {
        return age;
    }
public:
    Animals() : h(0), w(0), age(0), type("") {};
    Animals(int h, int w, int age, string type) : h(h), w(w), age(age) {
        // assert(age > 0); validation
        this-> age = age;
    };

//    virtual int getAgeToHumanAge() {
//        return getAge();
//    }
    virtual int getAgeToHumanAge() = 0;
    virtual void sayHello() = 0;
};

class Dog : public Animals {
    string name;
    string poroda;
public:
    Dog() : name (""), poroda("") { }
    Dog(int h, int w, int age, string type,  string name, string poroda) : Animals(h, w, age, type), poroda(poroda), name(name) {
    }
    void sayHello() {
        cout<<"Luv"<<endl;
    }

    int getAgeToHumanAge() override {
        return getAge() * 7;
    }
//    long getAgeToHumanAgeLong() override {
//        return getAge() * 7;
//    }

};
// const, static, auto, class
int override() {
    cout<<"BAD NAME FUNCTION..."<<endl;
}

void sayHelloWorld (Animals* animal) {
    animal->sayHello();
};
int main() {

//    Animals noAnimal();

    Dog *dog = new Dog(75, 15, 3, "Dog", "Sharo" , "Nemska ovcharka");
    Dog newDog(75, 15, 3, "Dog", "Sharo" , "Nemska ovcharka");
    // Animals newDogAnimal = (Animals)(newDog); // Not working....
    cout<<newDog.getAgeToHumanAge()<<endl;
    //cout<<newDogAnimal.getAgeToHumanAge()<<endl;
    //dog->sayHello();
    //cout<<dog->getAgeToHumanAge()<<endl;

    Animals *AnimalDog = dog;
    cout<<AnimalDog->getAgeToHumanAge()<<endl;
    sayHelloWorld(AnimalDog);
    delete dog;
    return 0;
}
