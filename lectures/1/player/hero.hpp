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

    template <typename HeroType1, typename HeroType2>
    static Hero* battle(HeroType1& hero1, HeroType2& hero2, unsigned prize = 1);
};

template <typename HeroType1, typename HeroType2>
Hero* Hero::battle(HeroType1& hero1, HeroType2& hero2, unsigned prize) {
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
    return winner;
}


/* Искаме да реализираме наследник SuperHero на Hero, който:

- има възможност да активира суперсила
- по подразбиране не е активирана
- като я активира си повишава нивото
- да може да се извежда
- подходящи конструктори, селектори и мутатори  
+ суперсилата да има име
*/

#endif