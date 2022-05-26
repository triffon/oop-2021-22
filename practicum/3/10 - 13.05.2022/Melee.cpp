#include "melee.h"

Melee::Melee() {
    this->speed = 0;
};

Melee::Melee(int speed, char const *name, double damage) : Weapon(name, damage) {
    this->speed = speed;
};

Melee::Melee(const Melee &other) : Weapon(other) {
    this->speed = other.speed;
};

Melee &Melee::operator=(const Melee &other) {

    if (this != &other) {
        Weapon::operator=(other);
        this->speed = speed;
    }

    return *this;
};
Melee::~Melee(){};

int Melee::getSpeed() const {
    return this->speed;
};

void Melee::hit() {
    std::cout << " Melee weapon hit " << getName() << std::endl;
}