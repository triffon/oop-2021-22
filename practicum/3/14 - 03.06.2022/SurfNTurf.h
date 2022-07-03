#pragma once
#include "MeatDish.h"
#include "SeafoodDish.h"

class SurfNTurf : public MeatDish, public SeafoodDish {
  public:
    SurfNTurf();
    SurfNTurf(const char **ingredients,
              int time, int numberOfIngredients, Meat meat, const char *fishName);
    SurfNTurf(SurfNTurf const &other);

    virtual ~SurfNTurf();

    void print() const;

    SurfNTurf &operator=(SurfNTurf const &other);
};
