#include <iostream>
#include "consultantUtils.h"
#include "computerShop.h"

int main ()
{
    Computer computer1("Lenovo", "i7", 3080, 1024, 5, 5, 1800, 1);
    Computer computer2("Lenovo", "i7", 3080, 1024, 5, 5, 1800, 1);
    Computer computer3("Lenovo", "i7", 3080, 1024, 5, 5, 1800, 1);
    Computer computer4("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer5("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer6("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer7("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer8("Acer", "i3", 2000, 200, 3, 5, 900, 1);
    Computer computer9("Asus", "i7", 5000, 2048, 4, 6, 2200, 1);
    
    ComputerShop myShop("Pesho's shop");
    myShop.addComputer(computer1);
    myShop.addComputer(computer2);
    myShop.addComputer(computer3);
    myShop.addComputer(computer4);
    myShop.addComputer(computer5);
    myShop.addComputer(computer6);
    myShop.addComputer(computer7);
    myShop.addComputer(computer8);
    myShop.addComputer(computer9);

    List<Computer> goodForGaming = myShop.filter(ConsultantUtils::isGoodForGaming);

    std::cout << "Good for gaming: " << std::endl;
    std::cout << goodForGaming << std::endl;

    List<Computer> goodForTravel = myShop.filter(ConsultantUtils::isGoodForTravel);

    std::cout << "Good for travel: " << std::endl;
    std::cout << goodForTravel << std::endl;

    return 0;
}