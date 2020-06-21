#pragma once

#include <uniform/platform/platform.hpp>

#define UF_COLOR_BUFFER_BIT 0x00004000

namespace Uniform
{
    namespace Renderer
    {
        void UNIFORM_API SwapBuffers(void *handle);
        void UNIFORM_API SetClearColor(float r, float g, float b);
        void UNIFORM_API Clear(unsigned mask);
    }
}