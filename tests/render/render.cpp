#include <glad/glad.h>

#include <uniform.hpp>
#include <logger.hpp>

#include <uniform/scene/renderer.hpp>
#include <uniform/core/math/matrix.hpp>

using namespace Uniform;

class Sandbox : public IApplication
{
public:

    Vector2f position, velocity;

    Sandbox() : IApplication("Uni-form", VideoMode(1200, 800),
        Window::Style::Resizable
    ), position(0.f, 0.f), velocity(0.f, 0.f) { }

    virtual void OnWindowResize(const Size2i size) override {
        Renderer::SetViewMatrix(Point2i(0, 0), size);
    }

    virtual bool OnUpdate(const int64_t elapsed_time) override {
        if ((int)(keyboard_pressed(Keyboard::Code::Up)) > 0) {
            velocity.y += 0.00005f;
        }

        if ((int)(keyboard_pressed(Keyboard::Code::Down)) > 0) {
            velocity.y -= 0.00005f;
        }

        if ((int)(keyboard_pressed(Keyboard::Code::Right)) > 0) {
            velocity.x += 0.00005f;
        }

        if ((int)(keyboard_pressed(Keyboard::Code::Left)) > 0) {
            velocity.x -= 0.00005f;
        }

        position += Renderer::GetModelViewMatrix() * velocity;

        if (position.x > 0.8) { position.x = 0.8, velocity.x = -(velocity.x / 2.f); }
        if (position.x < -0.8) { position.x = -0.8, velocity.x = -(velocity.x / 2.f); }

        if (position.y > 0.8) { position.y = 0.8, velocity.y = -(velocity.y / 2.f); }
        if (position.y < -0.8) { position.y = -0.8, velocity.y = -(velocity.y / 2.f); }

        #if defined(_DEBUG_)
         LOG_INFORMATION() << position << '\n';
        #endif

        Renderer::SetClearColor(0.f, 0.f, 0.f, 1.f);
        Renderer::Clear(UF_COLOR_BUFFER_BIT);

        glTranslatef(position.x, position.y, 0.f);
        glBegin(GL_QUADS);
         glVertex2d(-0.2, -0.2);
         glVertex2d(-0.2, 0.2);
         glVertex2d(0.2, 0.2);
         glVertex2d(0.2, -0.2);
        glEnd();
        glTranslatef(-position.x, -position.y, 0.f);
        glFlush();

        swap_buffers();
        return poll_events();
    }

};

Uniform::IApplication *Uniform::CreateApplication() {
    return new Sandbox();
}