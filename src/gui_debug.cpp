

#include "gui_debug.h"
#include "gui.h"
#include "../ImgWindow/ImgWindow.h"


ImFont *test25;
ImFont *test15;
void RenderDebugTools() {
    ImGui::ShowMetricsWindow();  // ImGui's built-in metrics window

    if (ImGui::Begin("Font Debug")) {
        if (test25) {
            ImGui::Text("test25 font loaded");
            ImGui::Text("test25 font size: %.2f", test25->FontSize);
        } else {
            ImGui::Text("test25 font is NULL");
        }

        if (test15) {
            ImGui::Text("test15 font loaded");
            ImGui::Text("test15 font size: %.2f", test15->FontSize);
        } else {
            ImGui::Text("test15 font is NULL");
        }
    ImGui::Text("Font Atlas:");
        ImGui::Image((void*)(intptr_t)test25->ContainerAtlas->TexID, ImVec2(test25->ContainerAtlas->TexWidth, test25->ContainerAtlas->TexHeight));
    }
    ImGui::End();
}
