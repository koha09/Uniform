#include <uniform/application/application.hpp>

#include <imgui.h>

#ifndef IMGUI_HPP
#define IMGUI_HPP

namespace Uniform
{
    namespace Modules
    {

        void UNIFORM_API ImGuiNewFrame();
        void UNIFORM_API ImGuiEndFrame();
        void UNIFORM_API ImGuiRenderDrawData();

        class UNIFORM_API ImGuiLayer : public ILayer
        {
        public:

            ImGuiLayer() = default;
            virtual ~ImGuiLayer() = default;

            virtual void OnAttach(Uniform::IApplication *application) override;
            virtual void OnDetach() override;

            virtual void OnStartFrame(const nanoseconds) override;
            virtual void OnEndFrame(const nanoseconds) override;

        };

    }
}

#endif