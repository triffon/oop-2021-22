#include "bot.hpp"

Bot::Bot(char const* _name, unsigned _score,
        char const* _algorithm, double _threshold,
        unsigned _difficulty) :
        Player(_name, _score),
        AI(_algorithm, _threshold),
        difficulty(_difficulty) {}

void Bot::print(std::ostream& os) const {
    Player::print(os);
    os << " и е бот с трудност " << getDifficulty();
    os << ", използващ ";
    AI::print(os);
}