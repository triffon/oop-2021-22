#include <iostream>

void testBuffer() {
    int x, y, z;
    std::cin >> x;
    std::cout << "x = " << x << std::endl;
    std::cin >> y;
    std::cout << "y = " << y << std::endl;
    std::cin >> z;
    std::cout << "z = " << z << std::endl;
    char s[10];
    std::cin.ignore();
    std::cin.getline(s, 10);
    std::cout << "s = " << s << std::endl;

    for(int i = 0; i < 3300; i++) {
        std::clog << i << ' ';
        for(int j = 0; j < 1E6; j++);
        if (i == 3243)
            std::cerr << "Бинго!" << std::endl;
    }
}

void testOutput() {
    char s[] = { 65, 67, 69, 10, 55, 56 };
    std::cout.write(s, 4);
    std::cout << s;
}

int main(int, char**) {
    testBuffer();
    //testOutput();
}
