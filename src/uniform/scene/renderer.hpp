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

        enum Primitives
        {
            Lines = 0x0001,
            Triangles = 0x0004,
            Quads = 0x0007,
        };

        void UNIFORM_API SetViewport(Point2i position, Size2i size);
        void UNIFORM_API SetClearColor(float r, float g, float b, float a);
        void UNIFORM_API Clear(uint32_t mask);

        void UNIFORM_API DrawArray(Primitives type, uint32_t first, uint32_t count);

    }
}

#endif