#include <uniform/uniform.hpp>
#include <logger/logger.hpp>

using namespace Uniform;

class Sandbox : public IApplication
{
public:

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ) { }

    void OnWindowMove(Vector2i position) override {
        #if defined(_DEBUG_)
         LOG_INFORMATION() << "OnWindowMove: " << position << '\n';
        #endif
    }

    void OnWindowResize(Vector2i size) override {
        #if defined(_DEBUG_)
         LOG_INFORMATION() << "OnWindowResize: " << size << '\n';
        #endif
    }

    bool OnUpdate(const float elapsed_time) override {
        return is_open();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}