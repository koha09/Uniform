#include <uniform/modules/imgui/imgui.hpp>

#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

using namespace Uniform::Modules;

void Uniform::Modules::ImGuiNewFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Uniform::Modules::ImGuiEndFrame() {
    ImGui::End();
    ImGui::Render();
}

void Uniform::Modules::ImGuiRenderDrawData() {
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::OnAttach(Uniform::IApplication *application) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)application->get_handle(), true);
    ImGui_ImplOpenGL3_Init("#version 150");
}

void ImGuiLayer::OnDetach() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::OnStartFrame(int64_t) {
    ImGuiNewFrame();
}

void ImGuiLayer::OnEndFrame(int64_t) {
    ImGuiEndFrame();
}