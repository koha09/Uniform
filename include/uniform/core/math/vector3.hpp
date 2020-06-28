#pragma once

#include <iostream>
#include <uniform/core/runtime.hpp>

namespace Uniform
{
    template <class _type>
    struct Vector3
    {

        _type x, y, z;

        Vector3() : x(_type()), y(_type()), z(_type()) { }
        Vector3(_type x, _type y, _type z) : x(x), y(y), z(z) { }

        constexpr size_t length() const {
            return 3;
        }

        _type operator[](size_t i) const {
            switch (i) {
                case (0): { return x; }
                case (1): { return y; }
                case (2): { return z; }
                default: { throw EXCEPTION_OUT_OF_RANGE; }
            } return x;
        }

        _type &operator[](size_t i) {
            switch (i) {
                case (0): { return x; }
                case (1): { return y; }
                case (2): { return z; }
                default: { throw EXCEPTION_OUT_OF_RANGE; }
            } return x;
        }

        friend Vector3 operator+(const Vector3 left, const Vector3 right) {
            return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
        }

        friend Vector3 operator+(const Vector3 left, const _type right) {
            return Vector3(left.x + right, left.y + right, left.z + right);
        }

        friend void operator+=(Vector3 &left, const Vector3 right) {
            left = left + right;
        }

        friend void operator+=(Vector3 &left, const _type right) {
            left = left + right;
        }

        friend Vector3 operator-(const Vector3 left, const Vector3 right) {
            return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
        }

        friend Vector3 operator-(const Vector3 left, const _type right) {
            return Vector3(left.x - right, left.y - right, left.z - right);
        }

        friend void operator-=(Vector3 &left, const Vector3 right) {
            left = left - right;
        }

        friend void operator-=(Vector3 &left, const _type right) {
            left = left - right;
        }

        friend Vector3 operator*(const Vector3 left, const Vector3 right) {
            return Vector3(left.x * right.x, left.y * right.y, left.z * right.z);
        }

        friend Vector3 operator*(const Vector3 left, const _type right) {
            return Vector3(left.x * right, left.y * right, left.z * right);
        }

        friend void operator*=(Vector3 &left, const Vector3 right) {
            left = left * right;
        }

        friend void operator*=(Vector3 &left, const _type right) {
            left = left * right;
        }

        friend Vector3 operator/(const Vector3 left, const Vector3 right) {
            return Vector3(left.x / right.x, left.y / right.y, left.z / right.z);
        }

        friend Vector3 operator/(const Vector3 left, const _type right) {
            return Vector3(left.x / right, left.y / right, left.z / right);
        }

        friend void operator/=(Vector3 &left, const Vector3 right) {
            left = left / right;
        }

        friend void operator/=(Vector3 &left, const _type right) {
            left = left / right;
        }
    };

    typedef Vector3<unsigned> Vector3u;
    typedef Vector3<int>      Vector3i;
    typedef Vector3<float>    Vector3f;
    typedef Vector3<double>   Vector3d;

    template <class _type>
    std::ostream &operator<<(std::ostream &stream, Vector3<_type> &right) {
        return stream << "{ " << right.x << ", " << right.y << ", " << right.z << " }";
    }

    template <class _type>
    std::ostream &operator<<(std::ostream &stream, const Vector3<_type> &right) {
        return stream << "{ " << right.x << ", " << right.y << ", " << right.z << " }";
    }
}