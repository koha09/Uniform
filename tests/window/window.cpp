#include <uniform/uniform.hpp>

class Sandbox : public Uniform::IApplication 
{
public:

    bool OnUpdate(const float elapsed_time) override {
        return true;
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}