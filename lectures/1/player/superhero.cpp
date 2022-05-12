#include <cstring>
#include "superhero.hpp"

SuperHero::SuperHero(char const* _name,
            unsigned _score,
            unsigned _level,
            char const* _power,
            bool _isActivated,
            unsigned _levelBoost)
    : Player(_name, _score),
      Hero(_name, _score, _level),
      isActivated(_isActivated),
      levelBoost(_levelBoost),
      power(nullptr) {
        setPower(_power);
}

SuperHero::SuperHero(SuperHero const& other)
  : Hero(other),
    isActivated(other.isActivated),
    levelBoost(other.levelBoost),
    power(nullptr) {
    setPower(other.power);
}

void SuperHero::setPower(char const* _power) {
    delete[] power;
    power = new char[strlen(_power) + 1];
    strcpy(power, _power);
}

SuperHero& SuperHero::operator=(SuperHero const& other) {
    if (this != &other) {
        // !!! Player::operator=(other);
        Hero::operator=(other);
        // *(Hero*)this = other;
        // (Hero&)*this = other;
        // !!!!! (Hero)*this = other;
        // *(Hero*)this = (Hero const&)other;
        // !!! *this = other;
        // !!! *this = (Hero)other
        setPower(other.power);
        isActivated = other.isActivated;
        levelBoost = other.levelBoost;
    }
    return *this;
}

SuperHero::~SuperHero() {
    // !!! Hero::~Hero();
    std::cout << "~SuperHero()\n";
    delete[] power;
}

unsigned SuperHero::getLevel() const {
    if (isActivated)
        return Hero::getLevel() + levelBoost;
    return Hero::getLevel();
}

void SuperHero::activatePower() {
    if (!isActivated) {
        isActivated = true;
//        level += levelBoost;
    }
}

void SuperHero::deactivatePower() {
    if (isActivated) {
        isActivated = false;
//        level -= levelBoost;
    }
}

void SuperHero::print(std::ostream& os) const {
    Player::print(os);
    os << " и е супергерой на ниво " << getLevel();
    os << " и има суперсила " << getPower() << ", която";
    if (!isUsingPower())
        os << " НЕ";
    os << " използва в момента";
}
