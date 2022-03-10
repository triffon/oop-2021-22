#include <iostream>
#include "point2d.hpp"

void testGeometry() {
    Point2D p, q(1, 3);
    p.printnl();
    q.printnl();
    p.read();
    p.printnl();
    std::cout << p.distanceToOrigin() << std::endl;
    std::cout << p.distanceTo(q) << std::endl;
    p.translate(q);
    p.printnl();
}

int main(int, char**) {
    testGeometry();
}
