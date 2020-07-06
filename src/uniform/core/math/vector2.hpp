#include <uniform/core/math/vector_fwd.hpp>
#include <uniform/core/runtime.hpp>

#include <ostream>

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

template <class _type>
struct Vector<_type, 2>
{

    _type x, y;

    Vector() : x(_type()), y(_type()) { }
    Vector(const _type v[2]) : x(v[0]), y(v[1]) { }
    Vector(const _type x, const _type y) : x(x), y(y) { }

    _type operator[](uint32_t i) const {
        constexpr _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y
        }; return this->*accessors[i];
    }

    _type &operator[](uint32_t i) {
        constexpr _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y
        }; return this->*accessors[i];
    }

    Vector operator+(const _type &r) const noexcept {
        return Vector(x + r, y + r);
    }

    Vector operator+(const Vector &r) const noexcept {
        return Vector(x + r.x, y + r.y);
    }

    Vector operator-(const _type &r) const noexcept {
        return Vector(x - r, y - r);
    }

    Vector operator-(const Vector &r) const noexcept {
        return Vector(x - r.x, y - r.y);
    }

    Vector operator*(const _type &r) const noexcept {
        return Vector(x * r, y * r);
    }

    Vector operator*(const Vector &r) const noexcept {
        return Vector(x * r.x, y * r.y);
    }

    Vector operator/(const _type &r) const {
        return Vector(x / r, y / r);
    }

    Vector operator/(const Vector &r) const {
        return Vector(x / r.x, y / r.y);
    }

    Vector &operator+=(const _type &r) noexcept {
        x += r, y += r;
        return *this;
    }

    Vector &operator+=(const Vector &r) noexcept {
        x += r.x, y += r.y;
        return *this;
    }

	Vector &operator-=(const _type &r) noexcept {
        x -= r, y -= r;
        return *this;
    }

    Vector &operator-=(const Vector &r) noexcept {
        x -= r.x, y -= r.y;
        return *this;
    }

    Vector &operator*=(const _type &r) noexcept {
        x *= r, y *= r;
        return *this;
    }

    Vector &operator*=(const Vector &r) noexcept {
        x *= r.x, y *= r.y;
        return *this;
    }

    Vector &operator/=(const _type &r) {
        x /= r, y /= r;
        return *this;
    }

    Vector &operator/=(const Vector &r) {
        x /= r.x, y /= r.y;
        return *this;
    }

    constexpr uint32_t size() const noexcept {
        return 2;
    }

};

typedef Vector<unsigned, 2> Vector2u;
typedef Vector<int,      2> Vector2i;
typedef Vector<float,    2> Vector2f;
typedef Vector<double,   2> Vector2d;

template <class _type>
std::ostream &operator<<(std::ostream &s, const Vector<_type, 2> &r) {
    return s << "{ " << r.x << ", " << r.y << " }";
}

#endif