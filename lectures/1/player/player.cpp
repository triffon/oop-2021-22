#include <cstring>
#include <iostream>
#include "player.hpp"

Player::Player(char const* _name, unsigned _score)
    : name(nullptr), score(_score) {
    setName(_name);
}

Player::Player(Player const& other) : name(nullptr), score(other.score) {
    setName(other.name);
}

Player::~Player() {
    std::clog << "~Player()\n";
    delete[] name;
}

void Player::print() const {
    std::cout << "Играчът '" << getName()
              << "' има " << getScore() << " точки" << std::endl;
}

void Player::setName(char const* _name) {
    // за домашно: strncpy
    delete[] name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

Player& Player::operator=(Player const& other) {
    if (this != &other) {
        setName(other.name);
        score = other.score;
    }
    return *this;
}