#pragma once

#include <iostream>
#include <uniform/core/runtime.hpp>

namespace Uniform
{
    template <class _type>
    struct Vector4
    {

        _type x, y, z, w;

        Vector4() : x(_type()), y(_type()), z(_type()), w(_type()) { }
        Vector4(_type x, _type y, _type z, _type w) : x(x), y(y), z(z), w(w) { }

        constexpr size_t length() const {
            return 4;
        }

        _type operator[](size_t i) const {
            switch (i) {
                case (0): { return x; }
                case (1): { return y; }
                case (2): { return z; }
                case (3): { return w; }
                default: { throw EXCEPTION_OUT_OF_RANGE; }
            } return x;
        }

        _type &operator[](size_t i) {
            switch (i) {
                case (0): { return x; }
                case (1): { return y; }
                case (2): { return z; }
                case (3): { return w; }
                default: { throw EXCEPTION_OUT_OF_RANGE; }
            } return x;
        }

        friend Vector4 operator+(const Vector4 left, const Vector4 right) {
            return Vector4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
        }

        friend Vector4 operator+(const Vector4 left, const _type right) {
            return Vector4(left.x + right, left.y + right, left.z + right, left.w + right);
        }

        friend void operator+=(Vector4 &left, const Vector4 right) {
            left = left + right;
        }

        friend void operator+=(Vector4 &left, const _type right) {
            left = left + right;
        }

        friend Vector4 operator-(const Vector4 left, const Vector4 right) {
            return Vector4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
        }

        friend Vector4 operator-(const Vector4 left, const _type right) {
            return Vector4(left.x - right, left.y - right, left.z - right, left.w - right);
        }

        friend void operator-=(Vector4 &left, const Vector4 right) {
            left = left - right;
        }

        friend void operator-=(Vector4 &left, const _type right) {
            left = left - right;
        }

        friend Vector4 operator*(const Vector4 left, const Vector4 right) {
            return Vector4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.w);
        }

        friend Vector4 operator*(const Vector4 left, const _type right) {
            return Vector4(left.x * right, left.y * right, left.z * right, left.w * right);
        }

        friend void operator*=(Vector4 &left, const Vector4 right) {
            left = left * right;
        }

        friend void operator*=(Vector4 &left, const _type right) {
            left = left * right;
        }

        friend Vector4 operator/(const Vector4 left, const Vector4 &right) {
            return Vector4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.w);
        }

        friend Vector4 operator/(const Vector4 left, const _type right) {
            return Vector4(left.x / right, left.y / right, left.z / right, left.w / right);
        }

        friend void operator/=(Vector4 &left, const Vector4 right) {
            left = left / right;
        }

        friend void operator/=(Vector4 &left, const _type right) {
            left = left / right;
        }
    };

    typedef Vector4<unsigned> Vector4u;
    typedef Vector4<int>      Vector4i;
    typedef Vector4<float>    Vector4f;
    typedef Vector4<double>   Vector4d;

    template <class _type>
    std::ostream &operator<<(std::ostream &stream, Vector4<_type> &right) {
        return stream << "{ " << right.x << ", " << right.y << ", " << right.z << ", " << right.w << " }";
    }

    template <class _type>
    std::ostream &operator<<(std::ostream &stream, const Vector4<_type> &right) {
        return stream << "{ " << right.x << ", " << right.y << ", " << right.z << ", " << right.w << " }";
    }
}