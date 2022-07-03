#include "melee.h"

class Axe : public Melee {
  public:
    Axe();
    Axe(int speed, const char *name, double damage);
    Axe(const Axe &other);

    virtual ~Axe();

    virtual void attack(const char *target);

    Axe &operator=(const Axe &other);
    virtual Weapon *clone() const;
};