#include "MeatDish.h"

MeatDish::MeatDish() : Dish(){};

MeatDish::MeatDish(const char **ingredients, int time, int numberOfIngredients, Meat meat)
    : Dish(ingredients, time, numberOfIngredients) {
    this->meat = meat;
};

MeatDish::MeatDish(MeatDish const &other) : Dish(other) {
    this->meat = other.meat;
};

MeatDish MeatDish::operator=(MeatDish const &other) {
    if (this != &other) {

        Dish::operator=(other);
        this->meat = other.meat;
    }
    return *this;
};

MeatDish::~MeatDish(){};

void MeatDish::print() const {
    std::cout << "Meat dish with ";
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
};