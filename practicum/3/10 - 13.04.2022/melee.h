#pragma once

#include "Weapon.h"

class Melee : public virtual Weapon {
  private:
    int speed;

  public:
    Melee();
    Melee(int speed, char const *name, double damage);
    Melee(const Melee &other);

    virtual ~Melee();

    int getSpeed() const;
    virtual void hit();

    Melee &operator=(const Melee &other);
};