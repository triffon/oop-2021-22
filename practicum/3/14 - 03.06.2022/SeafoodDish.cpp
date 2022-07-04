#include "SeafoodDish.h"

SeafoodDish::SeafoodDish() : Dish() {
    fishName = nullptr;
}

SeafoodDish::SeafoodDish(const char *fishName, const char **ingredients,
                         int time, int numberOfIngredients) : Dish(ingredients, time, numberOfIngredients) {
    int len = strlen(fishName);
    this->fishName = new char[len + 1];
    strcpy_s(this->fishName, len + 1, fishName);
}

SeafoodDish::SeafoodDish(const SeafoodDish &other) : Dish(other) {
    int len = strlen(other.fishName);
    this->fishName = new char[len + 1];
    strcpy_s(this->fishName, len + 1, other.fishName);
}

SeafoodDish &SeafoodDish::operator=(const SeafoodDish &other) {
    if (this != &other) {
        Dish::operator=(other);
        int len = strlen(other.fishName);
        strcpy_s(this->fishName, len + 1, other.fishName);
    }
    return *this;
}

SeafoodDish::~SeafoodDish() {
    if (fishName != nullptr)
        delete[] fishName;
}

void SeafoodDish::print() const {
    std::cout << "SeafoodDish is:" << fishName << std::endl;
    Dish::print();
}
