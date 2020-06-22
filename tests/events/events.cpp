#include <uniform.hpp>
#include <logger.hpp>

using namespace Uniform;

class Sandbox : public IApplication
{
public:

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ) { }

    virtual void OnWindowMove(const Point2i position) override {
        #if defined(_DEBUG_)
         LOG_INFORMATION() << "OnWindowMove: " << position << '\n';
        #endif
    }

    virtual void OnWindowResize(const Size2i size) override {
        #if defined(_DEBUG_)
         LOG_INFORMATION() << "OnWindowResize: " << size << '\n';
        #endif
    }

    virtual bool OnUpdate(const int64_t elapsed_time) override {
        return poll_events();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}