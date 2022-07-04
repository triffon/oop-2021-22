#pragma once
#include "Dish.h"
class SeafoodDish : virtual public Dish {
  protected:
    char *fishName;

  public:
    SeafoodDish();
    SeafoodDish(const char *fishName, const char **ingredients,
                int time, int numberOfIngredients);
    SeafoodDish(const SeafoodDish &other);

    virtual ~SeafoodDish();

    virtual void print() const;

    SeafoodDish &operator=(const SeafoodDish &other);
};
