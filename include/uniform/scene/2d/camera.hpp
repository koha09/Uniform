#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/core/math/vector2.hpp>

namespace Uniform
{
    class UNIFORM_API Camera2D
    {
    public:

        Camera2D(const Uniform::Vector2d position, const float rotate);
        virtual ~Camera2D() = default;

    private:

        Uniform::Vector2d _position;
        float _rotate;

    };
}