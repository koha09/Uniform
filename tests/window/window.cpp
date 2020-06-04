#include <uniform/uniform.hpp>
#include <logger/logger.hpp>

class Sandbox : public Uniform::IApplication
{
public:

    Sandbox() : IApplication("Uni-form", Uniform::VideoMode(1200, 800)) { }

    bool OnUpdate(const float elapsed_time) override {
        return is_open();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}