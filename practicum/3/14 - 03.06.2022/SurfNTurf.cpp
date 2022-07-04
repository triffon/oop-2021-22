#include "SurfNTurf.h"

SurfNTurf::SurfNTurf(const char **ingredients,
                     int time, int numberOfIngredients, Meat meat, const char *fishName)
    : Dish(ingredients, time, numberOfIngredients),
      MeatDish(ingredients, time, numberOfIngredients, meat),
      SeafoodDish(fishName, ingredients, time, numberOfIngredients) {}

SurfNTurf::SurfNTurf() : Dish(), MeatDish(), SeafoodDish() {}

SurfNTurf::~SurfNTurf() {}

SurfNTurf::SurfNTurf(SurfNTurf const &other) : Dish(other), MeatDish(other), SeafoodDish(other) {}

SurfNTurf &SurfNTurf::operator=(SurfNTurf const &other) {
    if (this != &other) {
        Dish::operator=(other);
        MeatDish::operator=(other);
        SeafoodDish::operator=(other);
    }
    return *this;
}

void SurfNTurf::print() const {
    std ::cout << "SurfNTurf : " << std::endl;
    std::cout << " with fish " << this->fishName;
    switch (this->meat) {
        case Meat::Beef:
            std::cout << "beef" << std::endl;
            break;
        case Meat::Chicken:
            std::cout << "chicken" << std::endl;
            break;
        case Meat::Pork:
            std::cout << "pork" << std::endl;
            break;
    }
    Dish::print();
}
