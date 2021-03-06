#include <uniform/core/math/vector_fwd.hpp>
#include <uniform/core/runtime.hpp>

#include <ostream>

#ifndef VECTOR4_HPP
#define VECTOR4_HPP

template <class _type>
struct Vector<_type, 4>
{

    _type x, y, z, w;

    Vector() : x(_type()), y(_type()), z(_type()), w(_type()) { }
    Vector(const _type v[4]) : x(v[0]), y(v[1]), z(v[2]), w(v[3]) { }
    Vector(const _type x, const _type y, const _type z, const _type w) : x(x), y(y), z(z), w(w) { }

    _type operator[](uint32_t i) const {
        constexpr _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y,
            &Vector::z,
            &Vector::w
        }; return this->*accessors[i];
    }

    _type &operator[](uint32_t i) {
        constexpr _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y,
            &Vector::z,
            &Vector::w
        }; return this->*accessors[i];
    }

    Vector operator+(const _type &r) const noexcept {
        return Vector(x + r, y + r, z + r, w + r);
    }

    Vector operator+(const Vector &r) const noexcept {
        return Vector(x + r.x, y + r.y, z + r.z, w + r.w);
    }

    Vector operator-(const _type &r) const noexcept {
        return Vector(x - r, y - r, z - r, w - r);
    }

    Vector operator-(const Vector &r) const noexcept {
        return Vector(x - r.x, y - r.y, z - r.z, w - r.w);
    }

    Vector operator*(const _type &r) const noexcept{
        return Vector(x * r, y * r, z * r, w * r);
    }

    Vector operator*(const Vector &r) const noexcept {
        return Vector(x * r.x, y * r.y, z * r.z, w * r.w);
    }

    Vector operator/(const _type &r) const {
        return Vector(x / r, y / r, z / r, w / r);
    }

    Vector operator/(const Vector &r) const {
        return Vector3(x / r.x, y / r.y, z / r.z, w / r.w);
    }

    Vector &operator+=(const _type &r) noexcept {
        x += r, y += r, z += r, w += r;
        return *this;
    }

    Vector &operator+=(const Vector &r) noexcept {
        x += r.x, y += r.y, z += r.z, w += r.w;
        return *this;
    }

	Vector &operator-=(const _type &r) noexcept {
        x -= r, y -= r, z -= r, w -= r;
        return *this;
    }

    Vector &operator-=(const Vector &r) noexcept {
        x -= r.x, y -= r.y, z -= r.z, w -= r.w;
        return *this;
    }

    Vector &operator*=(const _type &r) noexcept {
        x *= r, y *= r, z *= r, w *= r;
        return *this;
    }

    Vector &operator*=(const Vector &r) noexcept {
        x *= r.x, y *= r.y, z *= r.z, w *= r.w;
        return *this;
    }

    Vector &operator/=(const _type &r) {
        x /= r, y /= r, z /= r, w /= r;
        return *this;
    }

    Vector &operator/=(const Vector &r) {
        x /= r.x, y /= r.y, z /= r.z, w /= r.w;
        return *this;
    }

    constexpr uint32_t size() const noexcept {
        return 4;
    }

};

typedef Vector<unsigned, 4> Vector4u;
typedef Vector<int,      4> Vector4i;
typedef Vector<float,    4> Vector4f;
typedef Vector<double,   4> Vector4d;

template <class _type>
std::ostream &operator<<(std::ostream &l, const Vector<_type, 4> &r) {
    return l << "{ " << r.x << ", " << r.y << ", " << r.z << ", " << r.w << " }";
}

#endif