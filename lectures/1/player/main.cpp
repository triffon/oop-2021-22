#include <iostream>
#include <typeinfo>
#include "player.hpp"
#include "hero.hpp"
#include "superhero.hpp"
#include "ai.hpp"
#include "bot.hpp"
#include "boss.hpp"

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
    // !!! не работи при виртуално наследяване !!! Hero* ph = (Hero*)pp;
    // ph->println();
    // !!! не работи при виртуално наследяване !!! Hero& rh = (Hero&)rp;
    // rh.println();
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

void testPlayers() {
    Player* players[] = { new Player("Катнис Евърдийн", 1),
                          new Hero("Гандалф", 45, 10),
                          new SuperHero("Супермен", 100, 5, "летене", false, 10),
                          new SuperHero("Dr. Strange", 20, 8, "отваряне на портали", true, 9)
                        };
    size_t playerCount = sizeof(players) / sizeof(players[0]);
    for(int i = 0; i < playerCount; i++)
        players[i]->println();
    for(int i = 0; i < playerCount; i++)
        delete players[i];
}

void testAI() {
    AI ai("невронна мрежа", 0.2);
    ai.print();
}

void testBot() {
    Bot bot("Ботьо", 10, "невронна мрежа", 0.2, 5);
    bot.print();
    Bot bot1("Deep Thought", 20, "minimax", 3.8, 5),
        bot2("HAL 9000", 40, "alpha-beta", 1.9, 15);
}

void testBoss() {
    Boss boss("Саурон", 100, "тъмни сили", 1.2, 80, 50, 100);
    boss.print();
    std::cout << boss.getName() << std::endl;
    std::cout << &boss << std::endl;
    std::cout << ((Player&)(Hero&)boss).getName() << std::endl;
    std::cout << ((Player&)(Bot&)boss).getName() << std::endl;
    std::cout << &(Player&)(Hero&)boss << ' ' << &(Player&)(Bot&)boss << std::endl;
    std::cout << &(Player&)boss << std::endl;
    std::cout << &(Hero&)boss << ' ' << &(Bot&)boss << std::endl;
}

int main() {
    // testCopyPlayer();
    // testArrayPlayer();
    // testHero();
    // testSuperHero();
    // testPlayers();
    // testAI();
    // testBot();
    testBoss();
}

