#include <glad/glad.h>

#include <uniform.hpp>
#include <uniform/scene/renderer.hpp>
#include <uniform/modules/imgui/imgui.hpp>
#include <uniform/scene/texture.hpp>

#include <uniform/core/debug/logger.hpp>

#include <uniform/core/math/vector2.hpp>
#include <uniform/core/math/vector4.hpp>

using namespace Uniform;

int size = 1;
Vector4f position, velocity;

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    virtual bool OnUpdate(const nanoseconds elapsed_time) override {
        ImGui::Begin("Message");
        ImGui::Text("x: %f, y: %f", position.x, position.y);
        ImGui::SliderInt("size", &size, 1, 1000);
        ImGui::Text("Use WASD to move and ESC to close the program.");
        return true;
    }

};

class Sandbox : public IApplication
{
public:

    Texture *texture;

    Sandbox() : IApplication("Uniform", VideoMode(1200, 800),
        Window::Style::Resizable
    ) {
        push_layer(new ImGuiLayer);
    }

public:

    virtual void OnCreate() override {
        glEnable(GL_TEXTURE_2D);
        texture = new Texture("examples/resources/dev_info.png");
        LOGGER_CASE_INFORMATION(LOGGER_GET_TIME() << " : window created\n");
    }

    virtual bool OnUpdate(const nanoseconds elapsed_time) override {
        if ((int)(keyboard_pressed(Keyboard::Code::Escape)) > 0) {
            return false;
        }

        if ((int)(keyboard_pressed(Keyboard::Code::W)) > 0) {
            velocity.y += 0.000005f;
        }

        if ((int)(keyboard_pressed(Keyboard::Code::S)) > 0) {
            velocity.y -= 0.000005f;
        }

        if ((int)(keyboard_pressed(Keyboard::Code::D)) > 0) {
            velocity.x += 0.000005f;
        }

        if ((int)(keyboard_pressed(Keyboard::Code::A)) > 0) {
            velocity.x -= 0.000005f;
        }

        position += velocity * duration_cast<milliseconds>(elapsed_time).count();

        Renderer::SetClearColor(0.f, 0.f, 0.f, 1.f);
        Renderer::Clear(UF_COLOR_BUFFER_BIT);

        float qp_x = (1.f / get_size().x) * size;
        float qp_y = (1.f / get_size().y) * size;

        glTranslatef(position.x, position.y, 0);
        texture->bind(Texture::Buffer::texture_1);
        glBegin(GL_QUADS);
         glTexCoord2i(0, 0); glVertex2f(-qp_x, -qp_y);
         glTexCoord2i(0, 1); glVertex2f(-qp_x, qp_y);
         glTexCoord2i(1, 1); glVertex2f(qp_x, qp_y);
         glTexCoord2i(1, 0); glVertex2f(qp_x, -qp_y);
        glEnd();
        texture->unbind();
        glTranslatef(-position.x, -position.y, 0);

        Modules::ImGuiRenderDrawData();
        swap_buffers();
        return poll_events();
    }

    virtual void OnClose() override {
        LOGGER_CASE_INFORMATION(LOGGER_GET_TIME() << " : window closed\n");
    }

};

IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}