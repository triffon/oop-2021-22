#include <iostream>
#include <fstream>
#include "product.hpp"
#include "../stack/lstack.hpp"

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

void writeProductsInSafe(Product* products, size_t count, std::fstream& fs) {
    for(int i = 0; i < count; i++)
        products[i].write(fs);
}

void testWarehouse() {
    LinkedStack<Product> productsStack;

    const size_t MAX = 100;
    Product products[MAX];
    size_t count = readProducts(products);
    writeProducts(products, count);

    for(int i = 0; i < count; i++)
        productsStack.push(products[i]);

    while (!productsStack.empty())
        std::clog << productsStack.pop(); 

    std::ofstream of("products.txt");
    of << count << std::endl;
    writeProducts(products, count, of);

    std::fstream safe("safe.bin", std::ios::out | std::ios::binary);
    writeProductsInSafe(products, count, safe);
    safe.close();

    safe.open("safe.bin", std::ios::in | std::ios::out | std::ios::binary);
    Product product;
    product.read(safe, 110);
    std::cout << product;
    product.applyDiscount(0.1);
    product.write(safe);

    Product product2;
    product2.read(safe, 110);
    std::cout << product2;
    safe.close();
}

int main() {
    testWarehouse();
    return 0;
}
