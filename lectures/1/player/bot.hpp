#ifndef __BOT_HPP
#define __BOT_HPP
#include "player.hpp"
#include "ai.hpp"


class Bot : virtual public Player, public AI {
    unsigned difficulty;

public:
    Bot(char const* _name = "<някакъв бот>", unsigned _score = 0,
        char const* _algorithm = "<неизвестен алгоритъм>", double _threshold = 0.1,
        unsigned _difficulty = 1);
    Bot* clone() const { return new Bot(*this); }
    
    unsigned getDifficulty() const { return difficulty; }
    void setDifficulty(unsigned _difficulty) { difficulty = _difficulty; }

    void print(std::ostream& os = std::cout) const;
    void printDirect(std::ostream& os = std::cout) const;
};

#endif