#include "gui.h"
#include <cstddef>
#include <stdbool.h>
#include <memory>
#include <string>
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

  std::string menu_font = "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/resources/Roboto-Regular.ttf";
    
  test10 = io.Fonts->AddFontFromFileTTF(menu_font.c_str(), 10.0f, &config);
  if (test10 == NULL) {
    logMsg("test10 did not load");
  }

  test20 = io.Fonts->AddFontFromFileTTF(menu_font.c_str(), 20.0f, &config);
  if (test20 == NULL) {
    logMsg("test20 did not LOAD!");
  }

    logMsg("Menu Font: %s", menu_font.c_str());

  io.Fonts->Build();
}


void InitImGui() {
  ImGui::CreateContext();
  RecreateFontAtlas();
}


class ConfigureWindow : public ImgFontAtlas {
public:
  ConfigureWindow() : ImgFontAtlas(){
  
  ImgWindow::sFontAtlas = std::make_shared<ImgFontAtlas>();

  InitImGui();


  float w = ImGui::GetWindowWidth();
  
    ImVec4 nice_pink = ImColor(255, 150, 200);
    ImVec4 light_grey = ImColor(0xffb4a0aa);
    ImVec4 yellow = ImColor(247, 170, 61);
    ImVec4 red = ImColor(0xff, 0x33, 0x33);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);


    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(75, 620));

    ImGui::PushFont(test10);
    ImGui::Begin("SELECTION", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    

    // int oL, oT, oR, oB;
    // XPLMGetWindowGeometry(ImgWindow::GetWindowId(), &oL, &oT, &oR, &oB);
    // ImGui::TextWrapped("Left: %d, Top: %d, Right: %d, Bottom: %d", oL, oT, oR, oB);



    ImGui::End();


    ImGui::SetNextWindowPos(ImVec2(77, 0))  ;
    ImGui::SetNextWindowSize(ImVec2(1203, 620));
    
   
    
    ImGui::Begin("SETTINGS", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGui::PushFont(test20);
    ImGui::TextWrapped("Ilias 'Airfighter' Tselios !!!");
    ImGui::End();

    ImGui::PopFont();
    ImGui::PopStyleVar(1);


    ImGui::PopFont();



//    ImgWindow::sFontAtlas->AddFontFromFileTTF(menu_font, 20);



  // ImGuiIO &io = ImGui::GetIO();

  // io.Fonts->Clear();

  // io.Fonts->AddFontDefault();
 

  // char *menu_font = mkpathname(plugindir, "resources/fonts/Roboto-Regular.ttf", NULL);
  // ImgWindow::sFontAtlas->AddFontFromFileTTF(menu_font, 20);
    // logMsg("%s", menu_font);
  // lacf_free(menu_font);

  // ImFontConfig config;
  // config.OversampleH = 1;
  // config.OversampleV = 1;
  // config.GlyphExtraSpacing.x = 1.0f;

  // char *my_font1 = mkpathname(plugindir, "resources/fonts/menu.ttf", NULL);
  // logMsg("myfont: %s:", my_font1);
  // myfont18 = io.Fonts->AddFontFromFileTTF(my_font1, 18.0f, NULL,
  // io.Fonts->GetGlyphRangesDefault()); IM_ASSERT(myfont18 != NULL);
  // lacf_free(my_font1);

  // char *my_font2 = mkpathname(plugindir, "resources/fonts/menu.ttf", NULL);
  // myfont25 = io.Fonts->AddFontFromFileTTF(my_font2, 25.0f, NULL,
  // io.Fonts->GetGlyphRangesDefault()); lacf_free(my_font2);

  // Now we merge some icons from the OpenFontsIcons font into the above font
  // (see `imgui/docs/FONTS.txt`)

  // We only read very selectively the individual glyphs we are actually using
  // to safe on texture space
  // static ImVector<ImWchar> icon_ranges;
  // ImFontGlyphRangesBuilder builder;
  // Add all icons that are actually used (they concatenate into one string)
  // builder.AddText(
  //     ConfigureWindowICON_FA_SLIDERS ICON_FA_EXTERNAL_LINK_SQUARE_ALT ICON_FA_WINDOW_MAXIMIZE
  //         ICON_FA_WINDOW_MINIMIZE ICON_FA_WINDOW_RESTORE ICON_FA_WINDOW_CLOSE
  //             ICON_FA_TIMES_CIRCLE ICON_FA_BALANCE_SCALE ICON_FA_SAVE);

  // builder.BuildRanges(&icon_ranges);

  // ImgWindow::sFontAtlas->AddFontFromMemoryCompressedTTF(
  //     fa_solid_900_compressed_data, fa_solid_900_compressed_size, FONT_SIZE,
  //     &config, icon_ranges.Data);
 // config.MergeMode = true;
  // io.Fonts->Build();
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

   
    // ImGui::CreateContext();
    // ImGuiIO &io = ImGui::GetIO(); (void)io;
    // 
    // std::string font1 = "/mnt/916d7a1f-7d19-4354-823b-6606cd3a516e/X-Plane 12 Betas/Aircraft/ILIAS/P180_Avanti_II/plugins/avanti/resources/fonts/menu.ttf";
    //
    //  int width, height;
    //  unsigned char* pixels = NULL;
    // io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    // 
    // ImFont *menu_font = io.Fonts->AddFontFromFileTTF(font1.c_str(), 20.0f);
    // if (font1.c_str() == NULL) {
    //   logMsg("%s", font1.c_str());
    // }
    //
    //
    // io.Fonts->Build();

    float w = ImGui::GetWindowWidth();
  
    ImVec4 nice_pink = ImColor(255, 150, 200);
    ImVec4 light_grey = ImColor(0xffb4a0aa);
    ImVec4 yellow = ImColor(247, 170, 61);
    ImVec4 red = ImColor(0xff, 0x33, 0x33);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);


    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(75, 620));

    ImGui::PushFont(test10);
    ImGui::Begin("SELECTION", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

    

    int oL, oT, oR, oB;
    XPLMGetWindowGeometry(ImgWindow::GetWindowId(), &oL, &oT, &oR, &oB);
    ImGui::TextWrapped("Left: %d, Top: %d, Right: %d, Bottom: %d", oL, oT, oR, oB);



    ImGui::End();


    ImGui::SetNextWindowPos(ImVec2(77, 0))  ;
    ImGui::SetNextWindowSize(ImVec2(1203, 620));
    
   
    
    ImGui::Begin("SETTINGS", NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGui::PushFont(test20);
    ImGui::TextWrapped("Ilias 'Airfighter' Tselios !!!");
    ImGui::End();

    ImGui::PopFont();
    ImGui::PopStyleVar(1);


    ImGui::PopFont();
  }

private: 

};

ConfigureWindow *config = nullptr;
SettingsWindow *window = nullptr;

extern "C" {

  void Config() {

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





