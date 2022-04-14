#ifndef __PRODUCT_HPP
#define __PRODUCT_HPP

#include <iostream>

const size_t MAX_NAME = 100;
const unsigned INITIAL_ID = 100;

class Product {
    unsigned id;
    char name[MAX_NAME];
    float price;

public:
    Product(unsigned _id = 0, char const* _name = "неизвестен", float _price = 1.0);

    unsigned getId() const { return id; }
    char const* getName() const { return name; }
    float getPrice() const { return price; }

    void applyDiscount(float discount);

    // форматиран вход
    friend std::istream& operator>>(std::istream& is, Product&);

    // неформатиран вход
    void read(std::fstream& ifs, unsigned _id);

    // неформатиран изход
    void write(std::fstream& ofs) const;
};

// форматиран изход
std::ostream& operator<<(std::ostream& os, Product const&);

#endif