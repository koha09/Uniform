#include <uniform/core/math/matrix_fwd.hpp>

#include <uniform/core/math/vector_fwd.hpp>

#include <initializer_list>
#include <ostream>

#ifndef MATRIX3X3_HPP
#define MATRIX3X3_HPP

template <class _type, uint32_t _rows, uint32_t _columns>
class Matrix
{
public:

    Matrix() = default;

    Matrix(std::initializer_list<std::initializer_list<_type>> matrix) {
        uint32_t i = 0;
        for (auto &r : matrix) {
            std::copy(r.begin(), r.end(), _data[i++]);
        }
    }

    Matrix(const _type &fill) {
        std::fill(&_data[0][0], &_data[_rows][0], fill);
    }

    _type operator()(uint32_t row, uint32_t column) const {
        return _data[row][column];
    }

    _type &operator()(uint32_t row, uint32_t column) {
        return _data[row][column];
    }

    constexpr uint32_t rows() const {
        return _rows;
    }

    constexpr uint32_t columns() const {
        return _columns;
    }

    constexpr uint32_t size() const {
        return _rows * _columns;
    }

    _type *data() {
        return reinterpret_cast<_type*>(_data);
    }

private:

    _type _data[_rows][_columns];

};

typedef Matrix<unsigned, 3, 3> Matrix3x3u;
typedef Matrix<int,      3, 3> Matrix3x3i;
typedef Matrix<float,    3, 3> Matrix3x3f;
typedef Matrix<double,   3, 3> Matrix3x3d;

typedef Matrix<unsigned, 4, 4> Matrix4x4u;
typedef Matrix<int,      4, 4> Matrix4x4i;
typedef Matrix<float,    4, 4> Matrix4x4f;
typedef Matrix<double,   4, 4> Matrix4x4d;

template <class _type, uint32_t _rows, uint32_t _columns>
Vector<_type, _columns> operator*(const Matrix<_type, _rows, _columns> &l, const Vector<_type, _columns> &r) {
    Vector<_type, _columns> result;
    for (uint32_t col = 0; col < l.columns(); col++) {
        for (uint32_t row = 0; row < l.rows(); row++) {
            result[col] += l(col, row) * r[row];
        }
    } return result;
}

template <class _type, uint32_t _rows, uint32_t _columns>
Matrix<_type, _rows, _columns> operator*(Matrix<_type, _rows, _columns> l, const Matrix<_type, _rows, _columns> &r) {
    for (uint32_t col = 0; col < l.columns(); col++) {
        for (uint32_t row = 0; row < l.rows(); row++) {
            l(col, row) *=  r(col, row);
        }
    } return l;
}

template <class _type, uint32_t _rows, uint32_t _columns>
std::ostream &operator<<(std::ostream &s, const Matrix<_type, _rows, _columns> &r) {
    s << "{\n";
    for (uint32_t col = 0; col < r.columns(); col++) {
        s << " {";
        for (uint32_t row = 0; row < r.rows(); row++) {
            s << ' ' << r(col, row);
        } s << " }\n";
    }
    return s << "}";
}

#endif