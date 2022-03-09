#include <iostream>
#include "point3d.hpp"

Point3D::Point3D() {
    setP(Point2D());
    setZ(0);
}

Point3D::Point3D(Point2D const& _p, double _z) {
    setP(_p);
    setZ(_z);
}