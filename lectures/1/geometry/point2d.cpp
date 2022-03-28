#include <iostream>
#include <cmath>
#include "point2d.hpp"

Point2D::Point2D() {
    setX(0);
    setY(0);
}

Point2D::Point2D(double _x, double _y) {
    setX(_x);
    setY(_y);
}

// селектор за разстояние до центъра на координатната система
double Point2D::distanceToOrigin() const {
    //return distanceTo(Point2D());
    return sqrt(getX() * getX() + getY() * getY());
}
// селектор за разстояние до друга точка
double Point2D::distanceTo(Point2D const& p) const {
    /*
    double dx = p.getX() - getX();
    double dy = p.getY() - getY();
    return sqrt(dx * dx + dy * dy);
    */
   Point2D tthis = *this;
   tthis.reflectOrigin();
   tthis.translate(p);
   return tthis.distanceToOrigin();
}

// селектор за извеждане
void Point2D::print() const {
    std::cout << '(' << getX() << ", " << getY() << ')';
}

void Point2D::printnl() const {
    print();
    std::cout << std::endl;
}

// мутатор за въвеждане
void Point2D::read() {
    std::cin >> x >> y;
}

// транслация
void Point2D::translate(Point2D const& by) {
    // x += by.x;
    // y += by.y;
    setX(getX() + by.getX());
    setY(getY() + by.getY());
}
