#include <glad/glad.h>

#include <uniform.hpp>

#include <uniform/core/math/vector4.hpp>
#include <uniform/core/math/matrix.hpp>

#include <uniform/scene/renderer.hpp>
#include <uniform/modules/imgui/imgui.hpp>

#include <uniform/scene/shader.hpp>

#include <uniform/core/debug/logger.hpp>

using namespace Uniform;

float triangle_color[4] = { 0.f, 0.f, 0.f, 1.f };

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    virtual bool OnUpdate(const nanoseconds elapsed_time) override {
        ImGui::Begin("Message");
        ImGui::ColorEdit3("Color", triangle_color);
        return true;
    }

};

class Sandbox : public IApplication
{
public:

    Shader color_shader;

    Sandbox() : IApplication("Uniform", VideoMode(1200, 800)), color_shader(
        "#version 330 core\n"
        "layout (location = 0) in vec3 pos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(pos, 1.0);\n"
        "}",

        "#version 330 core\n"
        "out vec4 fragment_color;\n"
        "uniform vec4 color;\n"
        "void main()\n"
        "{\n"
        "   fragment_color = color;\n"
        "}"
    ) {
        push_layer(new ImGuiLayer);
    }

public:

    virtual void OnCreate() override {
        LOGGER_CASE_INFORMATION(LOGGER_GET_TIME() << " : window created\n");

        Matrix<float, 4, 2> vertices {
            { -0.5f, -0.5f },
            { -0.5f,  0.5f },
            {  0.5f,  0.5f },
            {  0.5f, -0.5f },
        };

        uint32_t v_buffer;
        glGenBuffers(1, &v_buffer);
        glBindBuffer(GL_ARRAY_BUFFER, v_buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

		color_shader.bind();
    }

    virtual bool OnUpdate(const nanoseconds elapsed_time) override {
        Renderer::SetClearColor(0.f, 0.f, 0.f, 1.f);
        Renderer::Clear(UF_COLOR_BUFFER_BIT);

        color_shader.set_float4("color", triangle_color);

        glEnableVertexAttribArray(0);
        glDrawArrays(GL_QUADS, 0, 4);
        glDisableVertexAttribArray(0);

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