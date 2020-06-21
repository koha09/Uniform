#include <uniform.hpp>
#include <logger.hpp>

using namespace Uniform;

class Layer1 : public ILayer {
public:

    bool OnUpdate(const int64_t elapsed_time) override {
        #if defined(_DEBUG_)
         LOG_INFORMATION() << "Message by Layer1!\n";
        #endif
        return true;
    }

};

class Layer2 : public ILayer {
public:

    bool OnUpdate(const int64_t elapsed_time) override {
        #if defined(_DEBUG_)
         LOG_INFORMATION() << "Message by Layer2!\n";
        #endif
        return true;
    }

};

class Sandbox : public IApplication
{
public:

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ) {
        push_layer(new Layer1);
        push_layer(new Layer2);
    }

    bool OnUpdate(const int64_t elapsed_time) override {
        return poll_events();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}