#include <iostream>
#include <sstream>
#include <iomanip>

void testBuffer() {
    int x, y, z;

    std::istringstream iss("10\n20\n30\nxyz");
    std::istream& is = iss; // std::cin;

    std::ostringstream oss;
    std::ostream& os = oss;// std::cout;

    is >> x;
    os << "x = " << x << std::endl;
    is >> y;
    os << "y = " << y << std::endl;
    is >> z;
    os << "z = " << z << std::endl;
    char s[10] = "abc";
    is.ignore();
    is.getline(s, 10);
    os << "s = " << s << std::endl;

    std::clog << "Програмата приключи!\n";
    std::clog << "Ето какво щеше да изведе на стандартния изход:\n" << oss.str();

    /*
    for(int i = 0; i < 3300; i++) {
        std::clog << i << ' ';
        for(int j = 0; j < 1E6; j++);
        if (i == 3243)
            std::cerr << "Бинго!" << std::endl;
    }
    */
}

void testOutput() {
    char s[] = { 65, 67, 69, 10, 55, 56 };
    std::cout.write(s, 4);
    std::cout << s;
}

void logState(std::istream& is = std::cin) {
    std::clog << "---------------------" << std::endl;
    std::clog << is.good() << std::endl;
    std::clog << is.bad() << std::endl;
    std::clog << is.eof() << std::endl;
    std::clog << is.fail() << std::endl;
    std::clog << is.rdstate() << std::endl;
    if (is)
        std::clog << "All is good!" << std::endl;
    else
        std::clog << "Something is bad..." << std::endl;
    std::clog << "---------------------" << std::endl;
}

void testState() {
    int x, y;
    logState();
    std::cin >> x;
    logState();
    // насилствено чупене на потока
    // std::cin.clear(std::ios::failbit | std::ios::eofbit);
    std::cin >> y;
    logState();
    std::cin.clear();
    logState();
    char c;
    std::cin.get(c);
    logState();
}

void testManipulators() {
    std::cout << 42 << std::hex << 42 << std::dec << 42 << std::endl;
    std::cout << std::setw(10) << std::right << std::setfill('?') << std::showbase << std::hex << 123 << std::endl;
    std::cout << 123 << std::endl;
    std::cout << std::setprecision(10) << 1.2345 << ' ' << std::setiosflags(std::ios::scientific) << 1.2345 << ' ' << std::fixed << 1.2345 << std::endl;
}

int main(int, char**) {
    //testBuffer();
    //testOutput();
    // testState();
    testManipulators();
}
