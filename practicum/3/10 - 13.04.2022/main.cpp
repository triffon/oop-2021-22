#include <iostream>

#include "Axe.h"
#include "Japanka.h"

int main() {
    Weapon *asd = new Japanka(12, 23, "penka", 12);
    asd->attack("ivancho");
    delete asd;
    return 0;
}