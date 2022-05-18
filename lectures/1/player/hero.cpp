#include "hero.hpp"

Hero::Hero(const char* _name, unsigned _score, unsigned _level)
    : Player(_name, _score), level(_level) {
    // ! score++;
    // !!! score = _score;
    // !!! setScore(_score);
}

void Hero::print(std::ostream& os) const {
    Player::print(os);
    printDirect(os);
}

void Hero::printDirect(std::ostream& os) const {
    os << " и е герой на ниво " << getLevel();
}

Hero* Hero::battle(Hero& hero1, Hero& hero2, unsigned prize) {
    std::cout << "==============================\n";
    std::cout << "Заформя се епична битка между:" << std::endl;
    hero1.println();
    std::cout << "и" << std::endl;
    hero2.println();
    std::cout << "Кой ще спечели?" << std::endl;
    Hero* winner = nullptr;
    if (hero1.getLevel() > hero2.getLevel())
        winner = &hero1;
    else if (hero2.getLevel() > hero1.getLevel())
        winner = &hero2;
    if (winner != nullptr)
        winner->addPoints(prize);
    std::cout << "==============================\n";
    return winner;
}
