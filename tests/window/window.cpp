#include <uniform.hpp>

using namespace Uniform;

class Sandbox : public IApplication
{
public:

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ) { }

    bool OnUpdate(const float elapsed_time) override {
        return is_open();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}