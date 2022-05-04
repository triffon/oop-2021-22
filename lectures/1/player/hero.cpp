#include "hero.hpp"

Hero::Hero(const char* _name, unsigned _score, unsigned _level)
    : Player(_name, _score), level(_level) {
    // ! score++;
    // !!! score = _score;
    // !!! setScore(_score);
}

void Hero::print(std::ostream& os) const {
    Player::print(os);
    os << " и е герой на ниво " << getLevel();
}

void Hero::println(std::ostream& os) const {
    print(os);
    os << std::endl;
}
