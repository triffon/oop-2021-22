#include <cstring>
#include "ai.hpp"

AI::AI(char const* _algorithm, double _threshold) : algorithm(nullptr), threshold(_threshold) {
    setAlgorithm(_algorithm);
}

void AI::setAlgorithm(char const* _algorithm) {
    delete[] algorithm;
    algorithm = new char[strlen(_algorithm) + 1];
    strcpy(algorithm, _algorithm);
}

AI::AI(AI const& other) : algorithm(nullptr), threshold(other.threshold) {
    setAlgorithm(other.algorithm);
}

AI& AI::operator=(AI const& other) {
    if (this != &other) {
        setAlgorithm(other.algorithm);
        threshold = other.threshold;
    }
    return *this;
}

AI::~AI() {
    delete[] algorithm;
}

void AI::print(std::ostream& os) const {
    os << "изкуствен интелект с алгоритъм " << getAlgorithm() << " и праг " << getThreshold();
}
