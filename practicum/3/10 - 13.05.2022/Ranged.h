#pragma once

#include "Weapon.h"

class Ranged : public virtual Weapon {
  private:
    int range;

  public:
    Ranged();
    Ranged(int range, char const *name, double damage);
    Ranged(const Ranged &other);

    virtual ~Ranged();

    int getRanged() const;
    virtual void shoot();

    Ranged &operator=(const Ranged &other);
};