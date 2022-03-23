#include <cstring>
#include <iostream>
#include "player.hpp"

Player::Player(char const* _name, unsigned _score)
    : score(_score) {
    setName(_name);
}

void Player::print() const {
    std::cout << "Играчът '" << getName()
              << "' има " << getScore() << " точки" << std::endl;
}

void Player::setName(char const* _name) {
    strcpy(name, _name);
}