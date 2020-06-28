#include <uniform/scene/2d/object.hpp>

Uniform::Object2D::Object2D(const Vector2d position, const double angle) : _position(position), _angle(angle) { }

Uniform::Vector2d Uniform::Object2D::get_position() const {
    return _position;
}

void Uniform::Object2D::set_position(const Vector2d position) {
    _position = position;
}

double Uniform::Object2D::get_rotation() const {
    return _angle;
}

void Uniform::Object2D::set_rotation(const double angle) {
    _angle = angle;
}