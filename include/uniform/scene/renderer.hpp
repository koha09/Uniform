#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/core/math/matrix.hpp>

#include <uniform/core/math/point2.hpp>
#include <uniform/core/math/size2.hpp>

#define UF_COLOR_BUFFER_BIT 0x00004000

namespace Uniform
{
    namespace Renderer
    {

        void UNIFORM_API SetViewMatrix(Point2i position, Size2i size);
        void UNIFORM_API SetClearColor(float r, float g, float b, float a);
        void UNIFORM_API Clear(unsigned mask);

        Uniform::Matrix<float, 4, 4> UNIFORM_API GetModelViewMatrix();

    }
}