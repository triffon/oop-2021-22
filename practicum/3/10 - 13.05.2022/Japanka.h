#pragma once

#include "Ranged.h"
#include "melee.h"

class Japanka : public Melee, public Ranged {
  public:
    Japanka();
    Japanka(int speed, int range, const char *name, double damage);
    Japanka(const Japanka &other);

    virtual ~Japanka();

    virtual void attack(const char *target);

    Japanka &operator=(const Japanka &other);

    virtual Weapon *clone() const;
};