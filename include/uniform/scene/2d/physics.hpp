#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/core/math/vector2.hpp>
#include <uniform/core/math/vector3.hpp>

namespace Uniform
{
    namespace Physics
    {

        double UNIFORM_API calculate_distance(Uniform::Vector2d position_1, Uniform::Vector2d position_2);

    }
}