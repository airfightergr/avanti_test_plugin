#pragma once

#include <string.h>
#include "XPLMDefs.h"
#include "XPLMPlugin.h"
#include "XPLMUtilities.h"
#include "XPLMPlanes.h"
#include "XPLMMenus.h"
#include "XPLMDataAccess.h"
#include "acfutils/dr.h"
// menu
// XPLMCommandRef show_settings_ui = NULL;
int show_settings_ui_handler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void *inRefcon);
void menu_init();
void menu_dref_init();
void menu_destroy();

