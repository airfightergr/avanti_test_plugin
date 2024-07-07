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


ImFont *test10;
ImFont *test20;
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

  test10 = io.Fonts->AddFontFromFileTTF(menu_font.c_str(), 10.0f, &config);
  if (test10 == NULL) {
    logMsg("test10 did not load");
  }

  test20 = io.Fonts->AddFontFromFileTTF(menu_font.c_str(), 20.0f, &config);
  if (test20 == NULL) {
    logMsg("test20 did not LOAD!");
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

  io.Fonts->Build();

    // Debugging: Check the glyphs in test20
    if (test20) {
        const ImFontGlyph* glyph = test20->FindGlyph('A');
        if (glyph) {
            logMsg("Glyph 'A' found in test20 font");
        } else {
            logMsg("Glyph 'A' not found in test20 font");
        }
    } else {
        logMsg("test20 font is NULL");
    }

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
        if (test10) {
            ImGui::Text("test10 font loaded");
            ImGui::Text("test10 font size: %.2f", test10->FontSize);
        } else {
            ImGui::Text("test10 font is NULL");
        }

        if (test20) {
            ImGui::Text("test20 font loaded");
            ImGui::Text("test20 font size: %.2f", test20->FontSize);
        } else {
            ImGui::Text("test20 font is NULL");
        }
    ImGui::Text("Font Atlas:");
        ImGui::Image((void*)(intptr_t)test10->ContainerAtlas->TexID, ImVec2(test10->ContainerAtlas->TexWidth, test10->ContainerAtlas->TexHeight));
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

    float w = ImGui::GetWindowWidth();
  
    ImVec4 nice_pink = ImColor(255, 150, 200);
    ImVec4 light_grey = ImColor(0xffb4a0aa);
    ImVec4 yellow = ImColor(247, 170, 61);
    ImVec4 red = ImColor(0xff, 0x33, 0x33);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);


    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(75, 620));

    if (test10 != NULL) {
    ImGui::PushFont(test10);
    } else {
      logMsg("test10 font is NULL");
    }
    ImGui::Begin("SELECTION", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    int oL, oT, oR, oB;
    XPLMGetWindowGeometry(ImgWindow::GetWindowId(), &oL, &oT, &oR, &oB);
    ImGui::TextWrapped("Left: %d, Top: %d, Right: %d, Bottom: %d", oL, oT, oR, oB);

    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(77, 0))  ;
    ImGui::SetNextWindowSize(ImVec2(1203, 620));
  
    
    ImGui::Begin("SETTINGS", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    
    if (test20 != NULL){
      ImGui::PushFont(test20);
    } else {
      logMsg("test20 font is NULL");
    }
    ImGui::TextWrapped("Ilias 'Airfighter' Tselios !!!");
    
    ImGui::End();

    ImGui::PopFont();
    ImGui::PopStyleVar(1);


    ImGui::PopFont();
     RenderDebugTools();

  }

private: 

};

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
}





