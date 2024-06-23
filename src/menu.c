

#include "XPLMMenus.h"
#include "XPLMUtilities.h"
#include "menu.h"


void setting_menu_handler (void *, void *inItemRef) {
  if (inItemRef == (void*)1) {
    XPLMCommandOnce(show_settings_ui);
  }
}


void menu_init(void) {

  show_settings_ui = XPLMCreateCommand("avanti/cmd/menu/show_settings_ui", "Show Settings UI");

  XPLMRegisterCommandHandler(show_settings_ui, show_settings_ui_handler, 1, (void*) 0);

  dr_create_i(&show_ui, (int *)&show_ui, B_TRUE, "avanti/menu/show_settings_ui");

  int setting_slot = XPLMAppendMenuItem(XPLMFindAircraftMenu(), "Settings", NULL, 0);
  XPLMMenuID settings_menu = XPLMCreateMenu("Avanti Settings", XPLMFindAircraftMenu(), setting_slot, setting_menu_handler, NULL);
  XPLMAppendMenuItem(settings_menu, "Settings Window", (void*)1, 0);

}


void menu_destroy(void) {
  XPLMUnregisterCommandHandler(show_settings_ui, show_settings_ui_handler, 0, 0);
}
