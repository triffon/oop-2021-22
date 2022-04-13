#include <iostream>
#include <fstream>
#include "product.hpp"

size_t readProducts(Product* products, std::istream& is = std::cin) {
    size_t count;
    if (&is == &std::cin)
        std::cout << "Моля, въведете брой продукти: ";
    is >> count;
    for(int i = 0; i < count; i++) {
        if (&is == &std::cin)
            std::cout << "Моля, въведете продукт " << i + 1 << std::endl;
        is >> products[i];
    }
    return count;
}

void writeProducts(Product* products, size_t count, std::ostream& os = std::cout) {
    for(int i = 0; i < count; i++)
        os << products[i];
}

void writeProductsInSafe(Product* products, size_t count, std::ofstream& ofs) {
    for(int i = 0; i < count; i++)
        products[i].write(ofs);
}

void testWarehouse() {
    const size_t MAX = 100;
    Product products[MAX];
    size_t count = readProducts(products);
    writeProducts(products, count);


    std::ofstream of("products.txt");
    of << count << std::endl;
    writeProducts(products, count, of);

    std::ofstream safe("safe.bin", std::ios::out | std::ios::binary);
    writeProductsInSafe(products, count, safe);
    safe.close();

    Product product;
    std::ifstream safe2("safe.bin", std::ios::in | std::ios::binary);
    product.read(safe2, 110);
    std::cout << product;
    product.applyDiscount(0.1);
    std::ofstream safe3("safe.bin", std::ios::out | std::ios::binary);
    product.write(safe3);
    safe3.close();

    std::ifstream safe4("safe.bin", std::ios::in | std::ios::binary);
    product.read(safe4, 110);
    std::cout << product;
    safe4.close();
}

int main() {
    testWarehouse();
    return 0;
}
