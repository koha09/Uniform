#pragma once

#include <uniform/core/math/vector2.hpp>
#include <uniform/core/math/vector3.hpp>
#include <uniform/core/math/vector4.hpp>

namespace Uniform
{
    template <class _type, size_t _size_h, size_t _size_v>
    class Matrix
    {
    public:

        _type *operator[](size_t index) const {
            return (_type*)_matrix[index];
        }

        _type *data() {
            return (_type*)_matrix;
        }

        friend Vector2<_type> operator*(const Matrix left, const Vector2<_type> right) {
            Vector2<_type> result;
            for (size_t d = 0; d < right.length(); d++) {
                for (size_t i = 0; i < left.size_v(); i++) {
                    result[d] += left[i][d] * right[d];
                }
            }
            return result;
        }

        friend Vector3<_type> operator*(const Matrix left, const Vector3<_type> right) {
            Vector3<_type> result;
            for (size_t d = 0; d < right.length(); d++) {
                for (size_t i = 0; i < left.size_v(); i++) {
                    result[d] += left[i][d] * right[d];
                }
            }
            return result;
        }

        friend Vector4<_type> operator*(const Matrix left, const Vector4<_type> right) {
            Vector4<_type> result;
            for (size_t d = 0; d < right.length(); d++) {
                for (size_t i = 0; i < left.size_v(); i++) {
                    result[d] += left[i][d] * right[d];
                }
            }
            return result;
        }

        constexpr size_t size_h() const {
            return _size_h;
        }

        constexpr size_t size_v() const {
            return _size_v;
        }

    private:

        _type _matrix[_size_h][_size_v];

    };
}