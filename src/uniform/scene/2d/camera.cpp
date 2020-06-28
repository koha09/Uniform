#include <uniform/scene/2d/camera.hpp>

Uniform::Camera2D::Camera2D(const Vector2d position, const double angle) : Object2D(position, angle) { }

double Uniform::Camera2D::get_zoom() const {
    return _zoom;
}

void Uniform::Camera2D::set_zoom(const double angle) {
    _zoom = angle;
}