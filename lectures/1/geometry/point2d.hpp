#ifndef __POINT2D_HPP
#define __POINT2D_HPP

#include <iostream>
#include <cmath>

template <typename T>
class Point2D {
private:
    T x, y;
public:
    // конструктори
    Point2D();
    Point2D(T _x, T _y);
    Point2D(Point2D<T> const&);
    // може и да се изпусне: Point2D(Point2D const&);

    // селектори за координатите
    T getX() const { return x; }
    T getY() const { return y; }

    // селектор за разстояние до центъра на координатната система
    double distanceToOrigin() const;
    // селектор за разстояние до друга точка
    double distanceTo(Point2D const&) const;

    // селектори за извеждане
    void print() const;
    void printnl() const;

    // мутатори за координати
    void setX(T _x) { x = _x; }
    void setY(T _y) { y = _y; }

    // мутатор за въвеждане
    void read();

    // отражения относно осите
    void reflectHorizontal() { setY(-getY()); }
    void reflectVertical()   { setX(-getX()); }
    void reflectOrigin()     { reflectHorizontal(); reflectVertical(); }

    // транслация
    void translate(Point2D const& by);
};

template <typename T>
Point2D<T>::Point2D() {
    std::clog << "Point2D()\n";
    setX(0);
    setY(0);
}

template <typename T>
Point2D<T>::Point2D(T _x, T _y) {
    std::clog << "Point2D(...)\n";
    setX(_x);
    setY(_y);
}

template <typename T>
Point2D<T>::Point2D(Point2D const& other) : x(other.x), y(other.y) {
    std::clog << "Point2D(Point2D const&)\n";
}

// селектор за разстояние до центъра на координатната система
template <typename T>
double Point2D<T>::distanceToOrigin() const {
    //return distanceTo(Point2D());
    return sqrt(getX() * getX() + getY() * getY());
}

template <typename T>// селектор за разстояние до друга точка
double Point2D<T>::distanceTo(Point2D const& p) const {
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


template <typename T>// селектор за извеждане
void Point2D<T>::print() const {
    std::cout << '(' << getX() << ", " << getY() << ')';
}

template <typename T>
void Point2D<T>::printnl() const {
    print();
    std::cout << std::endl;
}


template <typename T>// мутатор за въвеждане
void Point2D<T>::read() {
    std::cin >> x >> y;
}


template <typename T>// транслация
void Point2D<T>::translate(Point2D const& by) {
    // x += by.x;
    // y += by.y;
    setX(getX() + by.getX());
    setY(getY() + by.getY());
}

#endif