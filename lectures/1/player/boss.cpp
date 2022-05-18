#include "boss.hpp"

Boss::Boss(char const* _name, unsigned _score,
           char const* _algorithm, double _threshold,
           unsigned _level, unsigned _difficulty, unsigned _damage)
        : Player(_name, _score),
          Hero("игнорира се", _score, _level),
          Bot("също се игнорира", _score, _algorithm, _threshold, _difficulty),
          damage(_damage) {}

void Boss::print(std::ostream& os) const {
  Player::print(os);
  printDirect(os);
}

void Boss::printDirect(std::ostream& os) const {
    Bot::printDirect(os);
    std::cout << " и е бос, който";
    Hero::printDirect(os);
    std::cout << " и нанася щети " << getDamage() << std::endl;
}