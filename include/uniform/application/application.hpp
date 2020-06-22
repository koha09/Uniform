#pragma once

#include <uniform/platform/platform.hpp>

#include <uniform/application/window/window.hpp>

// TODO: Make own implementation of list
#include <list>

#include <cinttypes>

namespace Uniform
{
    class UNIFORM_API IApplication;

    class UNIFORM_API ILayer
    {
    public:

        ILayer() = default;
        virtual ~ILayer() = default;

        virtual void OnAttach(IApplication *application);
        virtual void OnDetach();

        virtual void OnStartFrame(const int64_t);
        virtual void OnEndFrame(const int64_t);

        virtual bool OnUpdate(const int64_t) = 0;

    };

    class UNIFORM_API IApplication : public Window
    {
    public:

        IApplication(const std::string title, const VideoMode mode, const size_t style = 0);
        virtual ~IApplication() = default;

        void run();

    protected:

        void push_layer(ILayer *layer);

        virtual bool OnUpdate(const int64_t) = 0;

    private:

        bool _running;
        std::list<ILayer*> _layers;

    };

    IApplication *CreateApplication();
}