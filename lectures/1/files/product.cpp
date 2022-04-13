#include <cstring>
#include <fstream>
#include "product.hpp"

Product::Product(unsigned _id, char const* _name, float _price)
    : id(_id), price(_price) {
    // !!! strcpy(name, _name);
    strncpy(name, _name, MAX_NAME);
    name[MAX_NAME - 1] = '\0';
}

void Product::applyDiscount(float discount) {
    if (discount > 0 && discount < 1)
        price *= (1 - discount);
}

std::istream& operator>>(std::istream& is, Product& product) {
    return (is >> product.id >> product.price).ignore().getline(product.name, MAX_NAME);
}

std::ostream& operator<<(std::ostream& os, Product const& product) {
    return os << product.getId() << ' ' <<
                 product.getPrice() << ' ' <<
                 product.getName() << std::endl;
}

void Product::write(std::ofstream& ofs) const {
    ofs.seekp((id - INITIAL_ID) * sizeof(Product));
    ofs.write((char const*)this, sizeof(Product));
}

void Product::read(std::ifstream& ifs, unsigned _id) {
    ifs.seekg((_id - INITIAL_ID) * sizeof(Product));
    ifs.read((char*)this, sizeof(Product));
}