#include <iostream>
#include <typeinfo>
#include "player.hpp"
#include "hero.hpp"
#include "superhero.hpp"

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

void testSuperHero() {
    std::cout << sizeof(Player) << std::endl;

    SuperHero superman("Супермен", 100, 5, "летене", false, 10);
    superman.println();
    SuperHero superman2 = superman;
    superman2.println();
    SuperHero superman3;
    superman3.println();
    superman3 = superman;
    superman3.println();
    superman.activatePower();
    superman.println();
    superman.deactivatePower();
    superman.println();

    Hero gandalf("Гандалф", 45, 10);
    Hero* winner = Hero::battle(superman, gandalf, 10);
    if (winner != nullptr) {
        std::cout << "Имаме победител!" << std::endl;
        winner->println();
    } else {
        std::cout << "Изглежда героите са равносилни!";
    }
    superman.activatePower();
    superman.println();
    winner = Hero::battle(superman, gandalf, 20);
    if (winner != nullptr) {
        std::cout << "Имаме победител!" << std::endl;
        winner->println();
    } else {
        std::cout << "Изглежда героите са равносилни!";
    }

    Hero* hero = &gandalf;
    winner = Hero::battle(superman, *hero, 30);
    if (winner != nullptr) {
        std::cout << "Имаме победител!" << std::endl;
        winner->println();
    } else {
        std::cout << "Изглежда героите са равносилни!";
    }

    std::cout << typeid(hero).name() << ' ' << typeid(*hero).name() << std::endl;

    if (typeid(*hero) == typeid(SuperHero))
        std::cout << "Я, това било супергерой!\n";

    hero = new SuperHero("Dr. Strange", 20, 8, "отваряне на портали", true, 9);

    std::cout << typeid(hero).name() << ' ' << typeid(*hero).name() << std::endl;

    if (typeid(*hero) == typeid(SuperHero))
        std::cout << "Я, това било супергерой!\n";

    winner = Hero::battle(superman, *hero, 40);
    if (winner != nullptr) {
        std::cout << "Имаме победител!" << std::endl;
        winner->println();
    } else {
        std::cout << "Изглежда героите са равносилни!";
    }

    ((SuperHero*)hero)->deactivatePower();
    winner = Hero::battle(superman, *hero, 50);
    if (winner != nullptr) {
        std::cout << "Имаме победител!" << std::endl;
        winner->println();
    } else {
        std::cout << "Изглежда героите са равносилни!";
    }

    std::cout << "Изтриваме hero:\n";
    delete hero;
    std::cout << "Изтрихме hero!\n";
}

int main() {
    // testCopyPlayer();
    // testArrayPlayer();
    // testHero();
    testSuperHero();
}

