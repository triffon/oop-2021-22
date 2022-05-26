#include "Axe.h"

Axe::Axe() : Weapon(), Melee() {}

Axe::Axe(int speed, const char *name, double damage) : Weapon(name, damage), Melee(speed, name, damage) {}

Axe::Axe(const Axe &other) : Weapon(other), Melee(other) {}

Axe &Axe::operator=(const Axe &other) {
    Melee::operator=(other);
    return *this;
}
Axe::~Axe() {}

void Axe::attack(const char *target) {
    std::cout << "Axe attacks target " << target << std::endl;
}