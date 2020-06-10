#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/application/window/window.hpp>
#include <uniform/application/layer/layer.hpp>

#include <deque>

namespace Uniform
{
    class UNIFORM_API IApplication : public Window
    {
    public:

        IApplication(std::string title, VideoMode mode, size_t style = 0);
        virtual ~IApplication() = default;

        void push_layer(ILayer *layer);

        virtual bool OnUpdate(const int64_t elapsed_time) = 0;

        void run();

    private:

        bool _running;
        std::deque<ILayer*> _layers;

    };

    IApplication *CreateApplication();
}