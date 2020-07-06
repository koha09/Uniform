#include <uniform/core/math/vector_fwd.hpp>
#include <uniform/core/runtime.hpp>

#include <ostream>

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

template <class _type>
struct Vector<_type, 3>
{

    _type x, y, z;

    Vector() : x(_type()), y(_type()), z(_type()) { }
    Vector(const _type v[3]) : x(v[0]), y(v[1]), z(v[2]) { }
    Vector(const _type x, const _type y, const _type z) : x(x), y(y), z(z) { }

    _type operator[](uint32_t i) const {
        constexpr _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y,
            &Vector::z
        }; return this->*accessors[i];
    }

    _type &operator[](uint32_t i) {
        constexpr _type Vector::*accessors[] = {
            &Vector::x,
            &Vector::y,
            &Vector::z
        }; return this->*accessors[i];
    }

    Vector operator+(const _type &r) const noexcept {
        return Vector(x + r, y + r, z + r);
    }

    Vector operator+(const Vector &r) const noexcept {
        return Vector(x + r.x, y + r.y, z + r.z);
    }

    Vector operator-(const _type &r) const noexcept {
        return Vector(x - r, y - r, z - r);
    }

    Vector operator-(const Vector &r) const noexcept {
        return Vector(x - r.x, y - r.y, z - r.z);
    }

    Vector operator*(const _type &r) const noexcept {
        return Vector(x * r, y * r, z * r);
    }

    Vector operator*(const Vector &r) const noexcept {
        return Vector(x * r.x, y * r.y, z * r.z);
    }

    Vector operator/(const _type &r) const {
        return Vector(x / r, y / r, z / r);
    }

    Vector operator/(const Vector &r) const {
        return Vector(x / r.x, y / r.y, z / r.z);
    }

    Vector &operator+=(const _type &r) noexcept {
        x += r, y += r, z += r;
        return *this;
    }

    Vector &operator+=(const Vector &r) noexcept {
        x += r.x, y += r.y, z += r.z;
        return *this;
    }

	Vector &operator-=(const _type &r) noexcept {
        x -= r, y -= r, z -= r;
        return *this;
    }

    Vector &operator-=(const Vector &r) noexcept {
        x -= r.x, y -= r.y, z -= r.z;
        return *this;
    }

    Vector &operator*=(const _type &r) noexcept {
        x *= r, y *= r, z *= r;
        return *this;
    }

    Vector &operator*=(const Vector &r) noexcept {
        x *= r.x, y *= r.y, z *= r.z;
        return *this;
    }

    Vector &operator/=(const _type &r) {
        x /= r, y /= r, z /= r;
        return *this;
    }

    Vector &operator/=(const Vector &r) {
        x /= r.x, y /= r.y, z /= r.z;
        return *this;
    }

    constexpr uint32_t size() const noexcept {
        return 3;
    }

};

typedef Vector<unsigned, 3> Vector3u;
typedef Vector<int,      3> Vector3i;
typedef Vector<float,    3> Vector3f;
typedef Vector<double,   3> Vector3d;

template <class _type>
std::ostream &operator<<(std::ostream &s, const Vector<_type, 3> &r) {
    return s << "{ " << r.x << ", " << r.y << ", " << r.z << " }";
}

#endif