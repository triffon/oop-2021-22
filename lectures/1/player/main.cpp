#include <iostream>
#include "player.hpp"

void anonymousPrint(Player p) {
    p.print();
    p.setName("<анонимен>");
    p.print();
}

Player createPlayer() {
    return "Нов играч";
}

void testCopyPlayer() {
    Player p1("Гандалф Сивия", 45);
    Player p2 = p1;
    p1.print();
    p2.print();
    p2.setName("Гандалф Белия");
    p1.print();
    p2.print();
    anonymousPrint(p2);
    p1.print();
    p2.print();
    // !!! Player bad("НВОАГаняогаяновгяантогяанотвгяаонтвягаонтвягаовнтьгаотянвьаогнтвьяаогнтвьаяогнтвьяаогтнвьяагнтовьяа");

    Player p3 = "Катнис Евърдийн";
    p3.print();

    anonymousPrint("Проба");
    createPlayer().print();
}

int main() {
    testCopyPlayer();
}