#include "boss.hpp"

Boss::Boss(char const* _name, unsigned _score,
           char const* _algorithm, double _threshold,
           unsigned _level, unsigned _difficulty, unsigned _damage)
        : Hero(_name, _score, _level),
          Bot(_name, _score, _algorithm, _threshold, _difficulty),
          damage(_damage) {}

void Boss::print(std::ostream& os) const {
    Bot::print(os);
    std::cout << " и е бос, който е ";
    Hero::print(os);
    std::cout << " и нанася щети " << getDamage() << std::endl;
}