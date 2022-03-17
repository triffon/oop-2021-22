#include <iostream>
#include "point2d.hpp"
#include "point3d.hpp"

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

void testGeometry3D() {
    Point3D p(1, 3, 8);
    p.printnl();
    Point3D q;
    q.read();
    p.translate(q);
    std::cout << p.distanceToOrigin() << std::endl;
    std::cout << p.distanceTo(q) << std::endl;
}

int main(int, char**) {
    // testGeometry();
    testGeometry3D();
}
