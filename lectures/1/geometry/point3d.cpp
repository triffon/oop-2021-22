#include <iostream>
#include "point3d.hpp"

Point3D::Point3D() {
    std::clog << "Point3D::Point3D()\n";
    setP(DPoint2D());
    setZ(0);
}

Point3D::Point3D(double _x, double _y, double _z) : p(_x, _y) {
    std::clog << "Point3D::Point3D(...)\n";
    getP().printnl();
 //   setP(DPoint2D(_x, _y));
    setZ(_z);
}

/*
Point3D::Point3D(Point3D const& other) : p(other.p), z(other.z) {
    // setP(other.getP());
    //setZ(other.getZ());
}
*/

Point3D::Point3D(DPoint2D const& _p, double _z) {
    setP(_p);
    setZ(_z);
}

void Point3D::print() const {
    // ((1,2),3)
    std::cout << '(' << getX() << ", " << getY() << ", " << getZ() << ')';
}

void Point3D::printnl() const {
    // this->Point3D::print();
    print();
    std::cout << std::endl;
}

void Point3D::read() {
    p.read();
    std::cin >> z;
    // std::cin >> x >> y >> z;
}

void Point3D::translate(Point3D const& p3d) {
    p.translate(p3d.getP());
    /*
    DPoint2D tmp = getP();
    tmp.translate(p3D.getP());
    setP(tmp);
    */
   setZ(getZ() + p3d.getZ());
}

double Point3D::distanceToOrigin() const {
    return DPoint2D(getP().distanceToOrigin(), getZ()).distanceToOrigin();
    /*
    double dp = getP().distanceToOrigin();
    DPoint2D q(dp, getZ());
    return q.distanceToOrigin();
    */
    // return sqrt(getX() * getX() + getY() * getY() + getZ() * getZ());
}

double Point3D::distanceTo(Point3D const& p) const {
    Point3D tthis = *this;
    tthis.reflectOrigin();
    tthis.translate(p);
    return tthis.distanceToOrigin();
}
