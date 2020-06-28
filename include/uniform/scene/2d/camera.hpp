#pragma once

#include <uniform/scene/2d/object.hpp>

namespace Uniform
{
    class UNIFORM_API Camera2D : Object2D
    {
    public:

        Camera2D(const Vector2d position, const double angle);
        virtual ~Camera2D() = default;

        double get_zoom() const;
        void set_zoom(const double angle);

    protected:

        double _zoom;

    };
}