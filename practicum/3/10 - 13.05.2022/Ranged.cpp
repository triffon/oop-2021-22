#include "Ranged.h"
#include "Weapon.h"

Ranged::Ranged() {
    this->range = 0;
};

Ranged::Ranged(int range, char const *name, double damage) : Weapon(name, damage) {

    this->range = range;
};

Ranged::Ranged(const Ranged &other) : Weapon(other) {
    this->range = other.range;
};

Ranged &Ranged::operator=(const Ranged &other) {

    if (this != &other) {
        Weapon::operator=(other);
        this->range = range;
    }

    return *this;
};
Ranged::~Ranged(){};

int Ranged::getRanged() const {
    return this->range;
};

void Ranged::shoot() {
    std::cout << "Ranged weapon shoot " << getName() << std::endl;
}