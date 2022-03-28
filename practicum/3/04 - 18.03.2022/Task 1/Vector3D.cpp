#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D() {
    this->x = 0;
    this->z = 0;
    this->y = 0;
}

Vector3D::Vector3D(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vector3D::normalize() {
    double tmp = this->getLenght();
    this->x /= tmp;
    this->y /= tmp;
    this->z /= tmp;
}

double Vector3D::getLenght() const {
    return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

Vector3D sum(const Vector3D &v1, const Vector3D &v2) {
    Vector3D result;
    
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    
    return result;
}

Vector3D product(const Vector3D &v, double multiple) {
    return Vector3D(v.x * multiple, v.y * multiple, v.z * multiple);
}

Vector3D diff(const Vector3D &v1, const Vector3D &v2) {
    Vector3D result;

    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    
    return result;
}

double productScalar(const Vector3D &v1, const Vector3D &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3D productVector(const Vector3D &v1, const Vector3D &v2) {
    Vector3D product;
    
    product.x = (v1.y * v2.z - v1.z * v2.y);
    product.y = (v1.z * v2.x - v1.x * v2.z);
    product.z = (v1.x * v2.y - v1.y * v2.x);
    
    return product;
}