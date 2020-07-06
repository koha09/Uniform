#include <uniform/application/window/window.hpp>

#include <chrono>
#include <list>

using namespace std::chrono;

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

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

        virtual void OnStartFrame(const nanoseconds);
        virtual void OnEndFrame(const nanoseconds);

        virtual bool OnUpdate(const nanoseconds) = 0;

    };

    class UNIFORM_API IApplication : public Window
    {
    public:

        IApplication(const std::string &title, const VideoMode &mode, uint32_t style = 0);
        virtual ~IApplication() = default;

        void run();

    protected:

        void push_layer(ILayer *layer);

        virtual void OnCreate();
        virtual bool OnUpdate(const nanoseconds) = 0;
        virtual void OnClose();

    private:

        bool _running;
        std::list<ILayer*> _layers;

    };

    IApplication *CreateApplication();
}


#endif