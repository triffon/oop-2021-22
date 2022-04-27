#include <iostream>
#include "player.hpp"
#include "hero.hpp"

void anonymousPrint(Player p) {
    std::clog << "anonymousPrint: В момента имаме " << Player::getPlayerCount() << " играчи" << std::endl;
    p.println();
    p.setName("<анонимен>");
    p.println();
}

Player createPlayer() {
    return "Нов играч";
}

void testCopyPlayer() {
    Player p1("Гандалф Сивия", 45);
    //Player p2 = p1;
    Player p2;
    p2 = p1;
    p2 = p2;
    p1.println();
    p2.println();
    p2.setName("Гандалф Белия");
    p1.println();
    p2.println();
    anonymousPrint(p2);
    p1.println();
    p2.println();
    // !!! Player bad("НВОАГаняогаяновгяантогяанотвгяаонтвягаонтвягаовнтьгаотянвьаогнтвьяаогнтвьаяогнтвьяаогтнвьяагнтовьяа");

    Player p3 = "Катнис Евърдийн";
    p3.println();

    anonymousPrint("Проба");
    createPlayer().print();

    std::clog << "В момента имаме " << Player::getPlayerCount() << " играчи" << std::endl;
}

void testArrayPlayer() {
    Player* players = new Player[10];
    // !!! delete players;
    delete[] players;
}

void testHero() {
    Hero gandalf("Гандалф Сивия", 45, 10);
    gandalf.println();
    // !!! std::cout << gandalf.score << std::endl;
    Player p = gandalf;
    p.println();
    Player* pp = &gandalf;
    pp->println();
    pp->setName("Гандалф Белия");
    gandalf.println();
    Player& rp = *pp;
    rp.println();

    Player katniss = "Катнис Евърдийн";
    // !!! pp = &katniss;
    // ! Hero h = (Hero const&)katniss;
    // ! h.println();
    Hero* ph = (Hero*)pp;
    ph->println();
    Hero& rh = (Hero&)rp;
    rh.println();
}

int main() {
    // testCopyPlayer();
    // testArrayPlayer();
    testHero();
}

