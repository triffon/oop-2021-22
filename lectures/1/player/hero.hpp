#ifndef __HERO_HPP
#define __HERO_HPP
#include "player.hpp"

class Hero : public Player {
    unsigned level;
public:

    // конструктор с параметри
    Hero(const char* _name = "<анонимен>",
           unsigned _score = 0,
           unsigned _level = 1);

    // селектор
    unsigned getLevel() const { return level; }

    // извеждане
    void print(std::ostream& os = std::cout) const;
    void println(std::ostream& os = std::cout) const;
};

#endif