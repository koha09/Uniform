#include <uniform/platform/platform.hpp>

#include <uniform/core/point2.hpp>
#include <uniform/core/size2.hpp>

#ifndef RENDERER_HPP
#define RENDERER_HPP

#define UF_COLOR_BUFFER_BIT 0x00004000

namespace Uniform
{
    namespace Renderer
    {

        void UNIFORM_API SetViewport(Point2i position, Size2i size);
        void UNIFORM_API SetClearColor(float r, float g, float b, float a);
        void UNIFORM_API Clear(uint32_t mask);

    }
}

#endif