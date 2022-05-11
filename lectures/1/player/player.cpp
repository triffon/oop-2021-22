#include <cstring>
#include "player.hpp"

unsigned Player::playerCount = 0;

Player::Player(char const* _name, unsigned _score)
    : name(nullptr), score(_score) {
    playerCount++;
    setName(_name);
    /*
    std::cout << "Конструктор на Player:\n-------------------\n";
    println();
    std::cout << "---------------------\n";
    */
}

Player::Player(Player const& other) : name(nullptr), score(other.score) {
    playerCount++;
    setName(other.name);
}

Player::~Player() {
    /*
    std::cout << "Деструктор на Player:\n-------------------\n";
    println();
    std::cout << "---------------------\n";
    */
    playerCount--;
    std::clog << "~Player()\n";
    delete[] name;
}

void Player::print(std::ostream& os) const {
    os << "Играчът '" << getName()
       << "' има " << getScore() << " точки";
}

void Player::println(std::ostream& os) const {
    print(os);
    os << std::endl;
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

unsigned Player::getPlayerCount() {
    return playerCount;
}