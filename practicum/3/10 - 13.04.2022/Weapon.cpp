#include "Weapon.h"

#pragma warning(disable : 4996)

Weapon::Weapon() {
    this->name = nullptr;
}

void Weapon::copy(const Weapon &weapon) {
    this->setName(weapon.name);
    this->setDamage(weapon.damage);
}

void Weapon::erase() {
    if (this->name != nullptr) {
        delete[] this->name;
        this->name = nullptr;
    }
}

Weapon::Weapon(char const *_name, double _damage) {
    this->setName(_name);
    this->setDamage(_damage);
}

Weapon::Weapon(Weapon const &weapon) {
    copy(weapon);
}

void Weapon::setName(const char *name) {
    erase();
    int length = strlen(name);
    this->name = new char[length + 1];
    strcpy(this->name, name);
}

void Weapon::setDamage(double damage) {
    this->damage = damage;
}

Weapon &Weapon::operator=(Weapon const &weapon) {
    if (this != &weapon) {
        copy(weapon);
    }
    return *this;
}

Weapon::~Weapon() {
    erase();
}
