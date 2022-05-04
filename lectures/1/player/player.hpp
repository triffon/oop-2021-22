#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include <iostream>

const int MAXNAME = 100;

class Player {
    //char name[MAXNAME];
    char* name;

    static unsigned playerCount;

protected:
    unsigned score;

    void addPoints(unsigned points) { score += points; }

public:

    Player(const char* _name = "<анонимен>", unsigned _score = 0);
    Player(Player const&);
    Player& operator=(Player const&);
    ~Player();

    char const* getName() const { return name; }
    unsigned getScore() const { return score; }

    void setName(char const* _name);

    virtual void print(std::ostream& os = std::cout) const;
    virtual void println(std::ostream& os = std::cout) const;

    static unsigned getPlayerCount();// { return playerCount; }
};

#endif