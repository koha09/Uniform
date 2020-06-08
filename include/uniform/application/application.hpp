#pragma once

#include <uniform/platform/platform.hpp>
#include <uniform/application/window/window.hpp>

namespace Uniform
{
    class UNIFORM_API IApplication : public Window
    {
    public:

        IApplication(std::string title, VideoMode mode, size_t style = 0);
        virtual ~IApplication();

        void run();

        virtual bool OnUpdate(const float elapsed_time) = 0;

    };

    IApplication *CreateApplication();
}