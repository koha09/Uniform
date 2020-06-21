#pragma once

#include <uniform/application/application.hpp>

#include <imgui.h>

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

            void OnAttach(Uniform::IApplication *application);
            void OnDetach();

            void OnStartFrame(int64_t);
            void OnEndFrame(int64_t);

        };

    }
}