#pragma once
#include <cstring>
#include <iostream>
class Weapon {
  private:
    char *name;
    double damage;
    void copy(const Weapon &weapon);
    void erase();

  public:
    Weapon();
    Weapon(char const *_name, double _damage);
    Weapon(Weapon const &weapon);

    virtual ~Weapon();

    const char *getName() const {
        return this->name;
    }
    void setName(const char *name);

    const double getDamage() const {
        return this->damage;
    }
    void setDamage(double damage);

    virtual void attack(const char *target) = 0;

    Weapon &operator=(Weapon const &weapon);
};
