#ifndef __POINT3D_HPP
#define __POINT3D_HPP
#include "point2d.hpp"

using DPoint2D = Point2D<double>;

class Point3D {
private:
//    double x, y, z;
    DPoint2D p;
    double z;
public:

    // конструктори
    Point3D();
    Point3D(DPoint2D const& _p, double _z);
    Point3D(double _x, double _y, double _z);
//    Point3D(Point3D const&);

    // селектори
    DPoint2D const& getP() const { return p; }
    double  getX() const { return p.getX(); }
    double  getY() const { return p.getY(); }
    double  getZ() const { return z; }

    // извеждане и въвеждане
    void print() const;
    void printnl() const;
    void read();

    // мутатори
    void setP(DPoint2D const& _p) { p = _p; }
    void setX(double _x) { p.setX(_x); }
    void setY(double _y) { p.setY(_y); }
    void setZ(double _z) { z = _z; }

    // разстояние
    double distanceToOrigin() const;
    double distanceTo(Point3D const& p) const;

    // транслация
    void translate(Point3D const& p);

    // отражение
    void reflectHorizontal() { setY(-getY()); }
    void reflectVertical()   { setX(-getX()); }
    void reflectDepth()      { setZ(-getZ()); }
    void reflectOrigin() {
        reflectHorizontal();
        reflectVertical();
        reflectDepth();
    }
};

#endif