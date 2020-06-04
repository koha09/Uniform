#pragma once

#include <uniform/platform/platform.hpp>
#include <uniform/application/window/window.hpp>

namespace Uniform
{
    class UNIFORM_API IApplication : public Window
    {
    public:

        IApplication(std::string title, VideoMode mode);
        virtual ~IApplication();

        void Run();

        virtual bool OnUpdate(const float elapsed_time) = 0;

    };

    IApplication *CreateApplication();
}