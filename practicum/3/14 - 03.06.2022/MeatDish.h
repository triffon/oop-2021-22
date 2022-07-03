#pragma once
#include "Dish.h"
enum class Meat {
    Beef,
    Pork,
    Chicken
};

class MeatDish : virtual public Dish {
  protected:
    Meat meat;

  public:
    MeatDish();
    MeatDish(const char **ingredients, int time, int numberOfIngredients, Meat meat);
    MeatDish(MeatDish const &other);

    virtual ~MeatDish();

    virtual void print() const;

    MeatDish operator=(MeatDish const &other);
};