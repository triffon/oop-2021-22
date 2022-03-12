#include "company.hpp"
#include "team.hpp"
#include "worker.hpp"
#include <iostream>

int main() {
    Worker pesho("pesho", 2, nullptr);
    Worker gosho("gosho", 1, &pesho);
    Worker stamat("stamat", 0.5, &gosho);
    pesho.printCEO();
    gosho.printCEO();
    stamat.printCEO();
    Worker t1e[2] = {Worker("pesho", 2, nullptr), Worker("gosho", 2, nullptr)};
    Worker t2e[2] = {Worker("gosho", 2, nullptr), Worker("stamat", 2, nullptr)};
    Team t1("t1", t1e, 2);
    Team t2("t2", t2e, 2);

    Team te[2] = {Team("t1", t1e, 2), Team("t2", t2e, 2)};

    Company c("komapniq", te, 2);
    std::cout << c.hasEmployee("pesho") << "\n";
    std::cout << c.hasEmployee("gosho") << "\n";
    std::cout << c.hasEmployee("stamat") << "\n";
    std::cout << c.hasEmployee("kiro") << "\n";
}
