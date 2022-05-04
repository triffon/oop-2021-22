#ifndef __SUPERHERO_HPP
#define __SUPERHERO_HPP

#include <iostream>
#include "hero.hpp"

class SuperHero : public Hero {
    char* power;
    bool isActivated;
    unsigned levelBoost;

    void setPower(char const* _power);

public:
    SuperHero(char const* _name = "<анонимен>",
              unsigned _score = 0,
              unsigned _level = 1,
              char const* _power = "<мистериозна>",
              bool _isActivated = false,
              unsigned _levelBoost = 1);

    SuperHero(SuperHero const&);
    SuperHero& operator=(SuperHero const&);
    ~SuperHero();

    void activatePower();
    void deactivatePower();
    void print(std::ostream& os = std::cout) const;
    void println(std::ostream& os = std::cout) const;
    unsigned getLevel() const;

    char const* getPower() const { return power; }
    bool isUsingPower() const { return isActivated; }
};


#endif