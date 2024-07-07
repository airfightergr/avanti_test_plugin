#include "gui.h"
#include <cstddef>
#include <stdbool.h>
#include <memory>
#include <string>
#include <fstream>
#include "../ImgWindow/ImgWindow.h"
#include "XPLMDisplay.h"
#include "XPLMGraphics.h"
#include "XPLMPlugin.h"
#include "acfutils/log.h"
#include "acfutils/helpers.h"


float scale = 1.0f;
char plugindir[MAX_PATH]{};
char *p;


std::string GetPluginPath() {

  XPLMGetPluginInfo(XPLMGetMyID(), NULL, plugindir, NULL, NULL);
  fix_pathsep(plugindir); // Fixes path separator per OS

  logMsg("Plugin full path: %s", plugindir);

  // cut off the trailing path to get the top plugin path
  if ((p = strrchr(plugindir, DIRSEP)) != NULL)
    *p = '\0';

  if ((p = strrchr(plugindir, DIRSEP)) != NULL) {
    if (strcmp(p + 1, "64") == 0 || strcmp(p + 1, "32") == 0 ||
        strcmp(p + 1, "win_x64") == 0 || strcmp(p + 1, "mac_x64") == 0 ||
        strcmp(p + 1, "lin_x64") == 0) {
      *p = '\0';
    }
  }

  logMsg("Plugin top folder: %s", plugindir);

  return plugindir;

}


void CreateFontTexture() {
    ImGuiIO& io = ImGui::GetIO();
    unsigned char* pixels;
    int width, height;

    // Retrieve the font texture data
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);

    // Upload texture to graphics system
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Store our identifier
    io.Fonts->TexID = (void*)(intptr_t)tex;
}



ImFont *test25;
ImFont *test15;
void RecreateFontAtlas() {
    // test Ben's code
  ImGuiIO& io = ImGui::GetIO();

  IM_DELETE(io.Fonts);

  io.Fonts = IM_NEW(ImFontAtlas);

  ImFontConfig config;
  config.OversampleH = 4;
  config.OversampleV = 4;
  config.PixelSnapH = false;
  config.MergeMode = false;

  std::string menu_font = "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/resources/fonts/menu.ttf";
  
   // Check if the font file exists
    std::ifstream font_file(menu_font.c_str());
    if (!font_file.good()) {
        logMsg("Font file does not exist: %s", menu_font.c_str());
        return;
    } else {
        logMsg("Font file exists: %s", menu_font.c_str());
    }
    font_file.close();

  static const ImWchar ranges[] = { 0x0020, 0x00FF, 0 }; // Basic Latin + Latin Supplement
    config.GlyphRanges = ranges;

  test25 = io.Fonts->AddFontFromFileTTF(menu_font.c_str(), 25.0f, &config);
  if (test25 == NULL) {
    logMsg("test10 did not load");
  }

  test15 = io.Fonts->AddFontFromFileTTF(menu_font.c_str(), 20.0f, &config);
  if (test15 == NULL) {
    logMsg("test15 did not LOAD!");
  }

    logMsg("Menu Font: %s", menu_font.c_str());

      // Ensure a default font is loaded
    if (io.Fonts->AddFontDefault() == NULL) {
        logMsg("Default font did not load");
    io.Fonts->AddFontDefault();
    } else {
        logMsg("Default font loaded successfully");
    io.Fonts->AddFontDefault();
    }

    if (!io.Fonts->Build()) {
        logMsg("Font atlas build failed");
    } else {
        logMsg("Font atlas build succeeded");
    }
    
    // Debugging: Check the glyphs in test15
    if (test15) {
        const ImFontGlyph* glyph = test15->FindGlyph('A');
        if (glyph) {
            logMsg("Glyph 'A' found in test15 font");
        } else {
            logMsg("Glyph 'A' not found in test15 font");
        }
    } else {
        logMsg("test15 font is NULL");
    }

  CreateFontTexture();

}


void InitImGui() {
  logMsg("Init imgui context");
  ImGui::CreateContext();
  logMsg("Imgui context created");
  RecreateFontAtlas();
  logMsg("font atlas created");
}

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

class ConfigureWindow : public ImgFontAtlas {
public:
  ConfigureWindow() : ImgFontAtlas(){
  
  ImgWindow::sFontAtlas = std::make_shared<ImgFontAtlas>();

}

virtual ~ConfigureWindow() {

  }


};


class SettingsWindow : public ImgWindow {
public:
  SettingsWindow(int left, int top, int right, int bottom) : ImgWindow(left, top, right, bottom) {
    
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    ImGuiStyle &style = ImGui::GetStyle();
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.25, 0.25, 0.25, 1.0);


    SetWindowTitle("Avanti Settings");
    SetWindowResizingLimits(1280, 620, 0, 0);
  }

  virtual ~SettingsWindow() {

  }


  virtual void buildInterface() override {

     // Ensure ImGui rendering uses the correct texture
    ImGuiIO& io = ImGui::GetIO();
    glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)io.Fonts->TexID);

    RenderDebugTools();  // Include the debug tools in your render loop

    float w = ImGui::GetWindowWidth();
  
    ImVec4 nice_pink = ImColor(255, 150, 200);
    ImVec4 light_grey = ImColor(0xffb4a0aa);
    ImVec4 yellow = ImColor(247, 170, 61);
    ImVec4 red = ImColor(0xff, 0x33, 0x33);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);


    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(75, 620));

    if (test15 != NULL) {
    ImGui::PushFont(test15);
    } else {
      logMsg("test15 font is NULL");
    }
    ImGui::Begin("SELECTION", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    int oL, oT, oR, oB;
    XPLMGetWindowGeometry(ImgWindow::GetWindowId(), &oL, &oT, &oR, &oB);
    ImGui::TextWrapped("Left: %d, Top: %d, Right: %d, Bottom: %d", oL, oT, oR, oB);

    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(77, 0))  ;
    ImGui::SetNextWindowSize(ImVec2(1203, 620));
  
    
    ImGui::Begin("SETTINGS", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    
    if (test25 != NULL){
      ImGui::PushFont(test25);
    } else {
      logMsg("test25 font is NULL");
    }
    ImGui::TextWrapped("Ilias 'Airfighter' Tselios !!!");
    
    ImGui::End();
    ImGui::PopFont();
    ImGui::PopStyleVar(1);
    ImGui::PopFont();

  }

private: 

};


void Render() {
    // Your rendering code

    // Ensure ImGui rendering uses the correct texture
    ImGuiIO& io = ImGui::GetIO();
    glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)io.Fonts->TexID);

    RenderDebugTools();  // Include the debug tools in your render loop
}


ConfigureWindow *config = nullptr;
SettingsWindow *window = nullptr;

extern "C" {

  void Config() {
  
  InitImGui();

  config = new ConfigureWindow();

  GetPluginPath();

  
  }
   

    void settings_show() {
      if (!window) {
          window = new SettingsWindow(100, 0, 100, 200);
      }
      window->SetVisible(!window->GetVisible());
    }

    bool settings_is_visible() {
          return window && window->GetVisible() && window->IsWindowInFront();
    }

    void settings_cleanup() {
          if(window) delete window;
    }

    // void RenderCallback() {
    //     // Ensure OpenGL context is active
    //
    //     // Your rendering code
    //     Render();  // Call your render function
    // }


}





