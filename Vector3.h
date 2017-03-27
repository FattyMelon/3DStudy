//
// Created by chensn on 2017/3/27.
//

#ifndef INC_3DSTUDY_VECTOR3_H
#define INC_3DSTUDY_VECTOR3_H


#include <exception>
#include <iostream>

class Vector3 {
public:
    friend Vector3 crossProduct(const Vector3 &lhs, const Vector3 &rhs);

    Vector3() {}
    Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z) {}
    Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

    //标准对象操作
    Vector3 &operator = (const Vector3 &v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    bool operator == (const Vector3 &rhs) const {
        return x == rhs.x && y == rhs.y && z == rhs.z;
    }

    bool operator != (const Vector3 &v) const {
        return !(*this == v);
    }

    //向量操作
    void zero () {
        x = y = z = 0;
    }

    // 一元负号
    Vector3 operator- () const {
        return Vector3(-x, -y, -z);
    }

    // 二元+和-
    Vector3 operator + (const Vector3 &rhs) {
        return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    Vector3 operator - (const Vector3 &rhs) {
        return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
    }

    // 标量乘除
    Vector3 operator * (float rhs) const {
        return Vector3(x * rhs, y * rhs, z * rhs);
    }

    Vector3 operator / (float rhs) const {
        try {
            float temp = 1.0f / rhs;
            return Vector3(x * temp, y * temp, z * temp);
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }

    Vector3 &operator += (const Vector3 &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    Vector3 &operator -= (const Vector3 &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Vector3 &operator *= (float rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    Vector3 &operator /= (float rhs) {
        try {
            float temp = 1.0f / rhs;
            x *= temp;
            y *= temp;
            z *= temp;
            return *this;
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }

    // 点乘
    float operator * (const Vector3 &rhs) const {
        return x*rhs.x + y * rhs.y + z * rhs.z;
    }

private:
    float x, y, z;
};

// 叉乘
inline  Vector3 crossProduct(const Vector3 &lhs, const Vector3 &rhs) {
    return Vector3(
            lhs.y * rhs.z - lhs.z * rhs.y,
            lhs.x * rhs.z - lhs.z * rhs.x,
            lhs.x * rhs.y - lhs.y * rhs.x
    );
}


#endif //INC_3DSTUDY_VECTOR3_H
