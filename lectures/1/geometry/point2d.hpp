#ifndef __POINT2D_HPP
#define __POINT2D_HPP

class Point2D {
private:
    double x, y;
public:
    // конструктори
    Point2D();
    Point2D(double _x, double _y);

    // селектори за координатите
    double getX() const { return x; }
    double getY() const { return y; }

    // селектор за разстояние до центъра на координатната система
    double distanceToOrigin() const;
    // селектор за разстояние до друга точка
    double distanceTo(Point2D const&) const;

    // селектори за извеждане
    void print() const;
    void printnl() const;

    // мутатори за координати
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }

    // мутатор за въвеждане
    void read();

    // отражения относно осите
    void reflectHorizontal() { setY(-getY()); }
    void reflectVertical()   { setX(-getX()); }
    void reflectOrigin()     { reflectHorizontal(); reflectVertical(); }

    // транслация
    void translate(Point2D const& by);
};

#endif