#pragma once

#include "Japanka.h"

Japanka::Japanka() : Weapon(), Melee(), Ranged() {}

Japanka::Japanka(int speed, int range, const char *name, double damage) : Weapon(name, damage), Melee(speed, name, damage), Ranged(range, name, damage) {}

Japanka::Japanka(const Japanka &other) : Weapon(other), Melee(other), Ranged(other) {}

Japanka &Japanka::operator=(const Japanka &other) {
    Melee::operator=(other);
    Ranged::operator=(other);
    return *this;
}
Japanka::~Japanka() {}

void Japanka::attack(const char *target) {
    std::cout << "Japanka " << getName() << "attacks target " << target << std::endl;
}

Weapon *Japanka::clone() const {
    return new Japanka(*this);
}