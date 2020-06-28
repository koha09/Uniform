#pragma once

#include <uniform/platform/platform.hpp>
#include <uniform/core/math/vector2.hpp>

namespace Uniform
{
    class UNIFORM_API Object2D
    {
    public:

        Object2D(const Vector2d position, const double angle);
        virtual ~Object2D() = default;

        Vector2d get_position() const;
        void set_position(const Vector2d position);

        double get_rotation() const;
        void set_rotation(const double angle);

    protected:

        Vector2d _position;
        double _angle;

    };
}