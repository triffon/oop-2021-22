#include "Dish.h";

#pragma warning(disable : 4996)

Dish::Dish() {
    numberOfIngredients = 0;
    time = 0;
}

Dish::Dish(const char **ingredients, int time, int numberOfIngredients) {
    for (size_t i = 0; i < numberOfIngredients; i++) {
        this->ingredients[i] = new char[strlen(ingredients[i]) + 1];
        for (int j = 0; j < i; j++) {
            if (false /*ravni*/) { // TODO
                throw std::invalid_argument("Repeating ingredients");
            }
        }
        strcpy(this->ingredients[i], ingredients[i]);
    }
    this->time = time;
    this->numberOfIngredients = numberOfIngredients;
}

Dish::Dish(const Dish &other) {
    this->time = other.time;
    this->numberOfIngredients = other.numberOfIngredients;
    for (size_t i = 0; i < numberOfIngredients; i++) {
        this->ingredients[i] = new char[strlen(other.ingredients[i]) + 1];
        strcpy(this->ingredients[i], other.ingredients[i]);
    }
}

Dish &Dish::operator=(const Dish &other) {

    if (this != &other) {
        for (int i = 0; i < numberOfIngredients; i++) {
            delete[] ingredients[i];
            this->ingredients[i] = new char[strlen(other.ingredients[i]) + 1];
            strcpy(this->ingredients[i], other.ingredients[i]);
        }
        this->numberOfIngredients = numberOfIngredients;
        this->time = time;
    }

    return *this;
};

Dish::~Dish() {
    for (int i = 0; i < numberOfIngredients; i++) {
        delete[] ingredients[i];
    }
}

void Dish::print() const {
    for (int i = 0; i < numberOfIngredients; i++) {
        std::cout << ingredients[i] << std::endl;
    }
    std::cout << " Time to cook " << time << std::endl;
};
