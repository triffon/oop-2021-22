#ifndef __PLAYER_HPP
#define __PLAYER_HPP

const int MAXNAME = 100;

class Player {
    //char name[MAXNAME];
    char* name;
    unsigned score;
public:

    Player(const char* _name = "<анонимен>", unsigned _score = 0);
    Player(Player const&);

    char const* getName() const { return name; }
    unsigned getScore() const { return score; }

    void setName(char const* _name);

    void print() const;
};

#endif