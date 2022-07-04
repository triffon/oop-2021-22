#pragma once
#include <cstring>
#include <iostream>

class Dish {
  protected:
    char *ingredients[128];
    int time;
    int numberOfIngredients;

  public:
    Dish();
    Dish(const char **ingredients, int time, int numberOfIngredients);
    Dish(const Dish &other);
    Dish &operator=(const Dish &other);

    virtual ~Dish();

    virtual void print() const;
};