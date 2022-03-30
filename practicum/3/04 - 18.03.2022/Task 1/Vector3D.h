#pragma once

class Vector3D {
  public:
    double x;
    double y;
    double z;

    Vector3D();
    Vector3D(double x, double y, double z);

    double getLenght() const;
    void normalize();
};

Vector3D sum(const Vector3D &v1, const Vector3D &v2);
Vector3D product(const Vector3D &v, double multiple);
Vector3D diff(const Vector3D &v1, const Vector3D &v2);
double productScalar(const Vector3D &v1, const Vector3D &v2);
Vector3D productVector(const Vector3D &v1, const Vector3D &v2);