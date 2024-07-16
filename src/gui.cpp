#include "gui.h"
#include <cstddef>
#include <cstdint>
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
#include "image_loader.h"
#include "globals.h"
#include "gui_debug.h"


float scale = 1.0f;


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


// Init fonts with ImFont *myfont;
ImFont *test25;
ImFont *test20;
ImFont *roboto18;
void RecreateFontAtlas() {
    
  ImGuiIO& io = ImGui::GetIO();

  IM_DELETE(io.Fonts);

  io.Fonts = IM_NEW(ImFontAtlas);

  ImFontConfig config;
  config.OversampleH = 4;
  config.OversampleV = 4;
  config.PixelSnapH = false;
  config.MergeMode = false;

  std::string menu_font = pluginDirectory + "resources/fonts/menu.ttf";
  std::string roboto_reg = pluginDirectory + "resources/fonts/Roboto-Regular.ttf";

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

  test20 = io.Fonts->AddFontFromFileTTF(menu_font.c_str(), 20.0f, &config);
  if (test20 == NULL) {
    logMsg("test20 did not LOAD!");
  }

  roboto18 = io.Fonts->AddFontFromFileTTF(roboto_reg.c_str(), 18.0f, &config);

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

  CreateFontTexture();

}


void InitImGui() {
  logMsg("Init imgui context");
  ImGui::CreateContext();
  logMsg("Imgui context created");
  RecreateFontAtlas();
  logMsg("font atlas created");
}


// init each image id with GLuint
GLuint cg_icon_id = 0;
GLuint company_logo_id = 0;
void load_gui_images() {
  std::string filename = pluginDirectory + "resources/images/cg_icon.png";
  cg_icon_id = loadImage(filename.c_str());

  std::string company_logo_file = pluginDirectory + "resources/images/company.png";
  company_logo_id = loadImage(company_logo_file.c_str());

  // debug
  if (cg_icon_id != 0 && company_logo_id != 0) {
    logMsg("Gui Images Loaded");
  }
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

    // RenderDebugTools();  // Include the debug tools in your render loop

    float w = ImGui::GetWindowWidth();
  
    ImVec4 nice_pink = ImColor(255, 150, 200);
    ImVec4 light_grey = ImColor(0xffb4a0aa);
    ImVec4 yellow = ImColor(247, 170, 61);
    ImVec4 red = ImColor(0xff, 0x33, 0x33);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);


    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(75, 620));


    // ImGui::Begin("SELECTION", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
    //
    // int oL, oT, oR, oB;
    // XPLMGetWindowGeometry(ImgWindow::GetWindowId(), &oL, &oT, &oR, &oB);
    // ImGui::TextWrapped("Left: %d, Top: %d, Right: %d, Bottom: %d", oL, oT, oR, oB);
    //
    // ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(0, 0))  ;
    ImGui::SetNextWindowSize(ImVec2(1280, 620));
    
    if (roboto18 != NULL) {
      ImGui::PushFont(roboto18);
    } else {
      logMsg("roboto18 font is NULL");
    } 
    
    // ImGui::Begin("##SETTINGS", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
   
    // Tab Bar
    if (ImGui::BeginTabBar("#tabs", ImGuiTabBarFlags_FittingPolicyDefault_)) {

      if (ImGui::BeginTabItem("CONFIGURATOR")) {

        if (test25 != NULL){
          ImGui::PushFont(test25);
        } else {
          logMsg("test25 font is NULL");
        }
        ImGui::TextWrapped("Ilias 'Airfighter' Tselios. All rights reserved. c 2024.");
        ImGui::PopFont(); //test25
        ImGui::EndTabItem();
      }

      if (ImGui::BeginTabItem("LOADING")) {
        if (cg_icon_id) {
          ImGui::Image((void *)(intptr_t)cg_icon_id, ImVec2(128, 128));
        }
        ImGui::EndTabItem();
      }

      if (ImGui::BeginTabItem("SOMETHING ELSE")) {
        if (company_logo_id) {
          ImGui::Image((void *)(intptr_t)company_logo_id, ImVec2(128,128)); 
        }
        ImGui::EndTabItem();
      }
    
    ImGui::EndTabBar();

    }

    // ImGui::End();
   

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

    // RenderDebugTools();  // Include the debug tools in your render loop
}


ConfigureWindow *config = nullptr;
SettingsWindow *window = nullptr;
void Config() {
  
  InitImGui();
  load_gui_images();
  config = new ConfigureWindow();
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
  // if(window) 
    delete window;
}
  






