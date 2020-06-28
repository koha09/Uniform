#pragma once

#include <iostream>
#include <uniform/core/runtime.hpp>

namespace Uniform
{
    template <class _type>
    struct Vector2
    {

        _type x, y;

        Vector2() : x(_type()), y(_type()) { }
        Vector2(_type x, _type y) : x(x), y(y) { }

        constexpr size_t length() const {
            return 2;
        }

        _type operator[](size_t i) const {
            switch (i) {
                case (0): { return x; }
                case (1): { return y; }
                default: { throw EXCEPTION_OUT_OF_RANGE; }
            } return x;
        }

        _type &operator[](size_t i) {
            switch (i) {
                case (0): { return x; }
                case (1): { return y; }
                default: { throw EXCEPTION_OUT_OF_RANGE; }
            } return x;
        }

        friend Vector2 operator+(const Vector2 left, const Vector2 right) {
            return Vector2(left.x + right.x, left.y + right.y);
        }

        friend Vector2 operator+(const Vector2 left, const _type right) {
            return Vector2(left.x + right, left.y + right);
        }

        friend void operator+=(Vector2 &left, const Vector2 right) {
            left = left + right;
        }

        friend void operator+=(Vector2 &left, const _type right) {
            left = left + right;
        }

        friend Vector2 operator-(const Vector2 left, const Vector2 right) {
            return Vector2(left.x - right.x, left.y - right.y);
        }

        friend Vector2 operator-(const Vector2 left, const _type right) {
            return Vector2(left.x - right, left.y - right);
        }

        friend void operator-=(Vector2 &left, const Vector2 right) {
            left = left - right;
        }

        friend void operator-=(Vector2 &left, const _type right) {
            left = left - right;
        }

        friend Vector2 operator*(const Vector2 left, const Vector2 right) {
            return Vector2(left.x * right.x, left.y * right.y);
        }

        friend Vector2 operator*(const Vector2 left, const _type right) {
            return Vector2(left.x * right, left.y * right);
        }

        friend void operator*=(Vector2 &left, const Vector2 right) {
            left = left * right;
        }

        friend void operator*=(Vector2 &left, const _type right) {
            left = left * right;
        }

        friend Vector2 operator/(const Vector2 left, const Vector2 right) {
            return Vector2(left.x / right.x, left.y / right.y);
        }

        friend Vector2 operator/(const Vector2 left, const _type right) {
            return Vector2(left.x / right, left.y / right);
        }

        friend void operator/=(Vector2 &left, const Vector2 right) {
            left = left / right;
        }

        friend void operator/=(Vector2 &left, const _type right) {
            left = left / right;
        }
    };

    typedef Vector2<unsigned> Vector2u;
    typedef Vector2<int>      Vector2i;
    typedef Vector2<float>    Vector2f;
    typedef Vector2<double>   Vector2d;

    template <class _type>
    std::ostream &operator<<(std::ostream &stream, Vector2<_type> &right) {
        return stream << "{ " << right.x << ", " << right.y << " }";
    }

    template <class _type>
    std::ostream &operator<<(std::ostream &stream, const Vector2<_type> &right) {
        return stream << "{ " << right.x << ", " << right.y << " }";
    }
}