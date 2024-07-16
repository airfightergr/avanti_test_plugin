#include "globals.h"
#include "XPLMPlugin.h"
#include "acfutils/log.h"
#include <cstddef>
#include <string>

std::string pluginPath;       // the full path to running .xpl
std::string pluginDirectory;  // the full path au to top plugin folder, with trailing /


void init_globals() {

  char pl_xpl_buff[512];
  XPLMGetPluginInfo(XPLMGetMyID(), NULL, pl_xpl_buff, NULL, NULL);
  pluginPath = pl_xpl_buff;

  logMsg("Running de_tha_doume.xpl: %s", pluginPath.c_str());


  // find the last slash and get the plugin path up to last slash '/'
  size_t lastSlashPos = pluginPath.find_last_of('/');
  if (lastSlashPos != std::string::npos) {
    size_t secondLastSlashPos = pluginPath.find_last_of('/', lastSlashPos - 1);
    if (secondLastSlashPos != std::string::npos) {
      pluginDirectory = pluginPath.substr(0, secondLastSlashPos + 1);
    }
    else {
      pluginDirectory = pluginPath;
    }
  }
  else {
    pluginDirectory = pluginPath;
  }

  logMsg("Plugin Folder: %s", pluginDirectory.c_str());
}
