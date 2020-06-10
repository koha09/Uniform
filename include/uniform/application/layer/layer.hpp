#pragma once

#include <uniform/platform/platform.hpp>

namespace Uniform
{
    class UNIFORM_API ILayer
    {
    public:

        ILayer() = default;
        virtual ~ILayer() = default;

        virtual bool OnUpdate(const int64_t elapsed_time) = 0;

    };
}