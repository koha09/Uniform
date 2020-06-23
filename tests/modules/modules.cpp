#include <uniform.hpp>

#include <uniform/modules/imgui/imgui.hpp>
#include <uniform/scene/renderer.hpp>

using namespace Uniform;

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    virtual bool OnUpdate(const int64_t elapsed_time) override {
        ImGui::Begin("Message");
        ImGui::Text("I work... I do not know, miracle is probably.");
        ImGui::Text("Elapsed time: %" PRId64 "ns", elapsed_time);
        return true;
    }

};

class Sandbox : public IApplication
{
public:

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ) {
        push_layer(new ImGuiLayer);
    }

    virtual bool OnUpdate(const int64_t elapsed_time) override {
        Uniform::Renderer::SetClearColor(0.20f, 0.25f, 0.30f);
        Uniform::Renderer::Clear(UF_COLOR_BUFFER_BIT);
        Uniform::Modules::ImGuiRenderDrawData();
        swap_buffers();
        return poll_events();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}