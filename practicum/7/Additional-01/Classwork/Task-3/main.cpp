#include "Book.h"

int main(){
    Book b("Hello", "World", 1940, 10);
    std::ofstream os("file.dat", std::ios::binary);
    os << b;
    os.close();
    Book c("Test", "Test", 22,12);
    std::ifstream is("file.dat", std::ios::binary);
    is >> c;
    c.printBook();
    is.close();
}