#include <iostream>
#pragma warning(disable : 4996)
#include "SurfNTurf.h"

int main() {
    char *asd[23];
    asd[0] = new char[100];
    asd[1] = new char[100];
    strcpy(asd[0], "a");
    strcpy(asd[1], "a");
    try {
        SurfNTurf d((const char **)asd, 2, 2, Meat::Pork, "nemo");
        d.print();
    } catch (std::logic_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}