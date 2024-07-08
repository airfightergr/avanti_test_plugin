/*
 * Avanti Plugin for X-Plane
*/

#include "main.h"
#include "XPLMProcessing.h"
#include "menu.h"
#include "gui.h"


float MyLoopCB(float elapsedMe, float elapsedSim, int counter, void * refcon);


PLUGIN_API int XPluginStart(char *outName, char *outSig, char *outDesc) {
  XPLMEnableFeature("XPLM_USE_NATIVE_PATHS", 1);
  XPLMEnableFeature("XPLM_WANTS_DATAREF_NOTIFICATION", 1);

  // plugin info
  strcpy(outName, "Avanti Plugin");
  strcpy(outSig, "com.ilias.avanti");
  strcpy(outDesc, "Plugin for Avanti aircraft");

  XPLMRegisterFlightLoopCallback(MyLoopCB, 1.0, NULL);

  log_init(XPLMDebugString, "[P-180 AVANTI]: ");
  logMsg("Plugin version: 3.0.0.a");


  // Initializations
  glewInit();
  menu_init();
   
  return 1;

}


PLUGIN_API int XPluginEnable(void) {

  Config();
 
  menu_dref_init();

  return 1;
}


PLUGIN_API void XPluginReceiveMessage(XPLMPluginID id, intptr_t inMessage, void * inParam) {
    UNUSED(id);
    UNUSED(inMessage);
    UNUSED(inParam);
}


float MyLoopCB(float elapsedMe, float elapsedSim, int counter, void * refcon) {

  // RenderCallback();
  return 0.1;
}



int show_settings_ui_handler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void *inRefcon) {

  if(inPhase == 0) {
    settings_show();
  }

  return 0;
}


PLUGIN_API void XPluginStop(void) {

  menu_destroy();
}


PLUGIN_API void XPluginDisable(void) {

  menu_destroy();
}






