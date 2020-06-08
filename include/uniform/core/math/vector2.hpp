#pragma once

#include <iostream>

namespace Uniform
{
    template <class _type>
    class Vector2
    {
    public:

        _type x, y;

        Vector2() : x(_type()), y(_type()) { }
        Vector2(_type x, _type y) : x(x), y(y) { }

    };

    typedef Vector2<unsigned> Vector2u;
    typedef Vector2<int>      Vector2i;
    typedef Vector2<float>    Vector2f;
    typedef Vector2<double>   Vector2d;

    template <class _type>
    Vector2<_type> operator+(Vector2<_type> &left, Vector2<_type> &right) {
        return Vector2<_type>(left.x + right.x, left.y + right.y);
    }

    template <class _type>
    Vector2<_type> operator+(Vector2<_type> &left, const _type right) {
        return Vector2<_type>(left.x + right, left.y + right);
    }

    template <class _type>
    void operator+=(Vector2<_type> &left, Vector2<_type> &right) {
        left = left + right;
    }

    template <class _type>
    void operator+=(Vector2<_type> &left, const _type right) {
        left = left + right;
    }

    template <class _type>
    Vector2<_type> operator-(Vector2<_type> &left, Vector2<_type> &right) {
        return Vector2<_type>(left.x - right.x, left.y - right.y);
    }

    template <class _type>
    Vector2<_type> operator-(Vector2<_type> &left, const _type right) {
        return Vector2<_type>(left.x - right, left.y - right);
    }

    template <class _type>
    void operator-=(Vector2<_type> &left, Vector2<_type> &right) {
        left = left - right;
    }

    template <class _type>
    void operator-=(Vector2<_type> &left, const _type right) {
        left = left - right;
    }

    template <class _type>
    Vector2<_type> operator*(Vector2<_type> &left, Vector2<_type> &right) {
        return Vector2<_type>(left.x * right.x, left.y * right.y);
    }

    template <class _type>
    Vector2<_type> operator*(Vector2<_type> &left, const _type right) {
        return Vector2<_type>(left.x * right, left.y * right);
    }

    template <class _type>
    void operator*=(Vector2<_type> &left, Vector2<_type> &right) {
        left = left * right;
    }

    template <class _type>
    void operator*=(Vector2<_type> &left, const _type right) {
        left = left * right;
    }

    template <class _type>
    Vector2<_type> operator/(Vector2<_type> &left, Vector2<_type> &right) {
        return Vector2<_type>(left.x / right.x, left.y / right.y);
    }

    template <class _type>
    Vector2<_type> operator/(Vector2<_type> &left, const _type right) {
        return Vector2<_type>(left.x / right, left.y / right);
    }

    template <class _type>
    void operator/=(Vector2<_type> &left, Vector2<_type> &right) {
        left = left / right;
    }

    template <class _type>
    void operator/=(Vector2<_type> &left, const _type right) {
        left = left / right;
    }

    template <class _type>
    std::ostream &operator<<(std::ostream &stream, Vector2<_type> &right) {
        return stream << "{ " << right.x << ", " << right.y << " }";
    }
}