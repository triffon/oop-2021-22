#ifndef __BOSS_HPP
#define __BOSS_HPP
#include "hero.hpp"
#include "bot.hpp"

class Boss : public Hero, public Bot {
    unsigned damage;
public:
    Boss(char const* _name = "<някакъв бос>", unsigned _score = 0,
        char const* _algorithm = "<неизвестен алгоритъм>", double _threshold = 0.1,
        unsigned _level = 20, unsigned _difficulty = 1, unsigned _damage = 10);
    Boss* clone() const { return new Boss(*this); }

    unsigned getDamage() const { return damage; }

    void print(std::ostream& os = std::cout) const;
    void printDirect(std::ostream& os = std::cout) const;
};

#endif