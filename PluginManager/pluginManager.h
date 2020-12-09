#ifndef PLUGINMANAGER_GRAPHICEDITOR_H
#define PLUGINMANAGER_GRAPHICEDITOR_H

#include "../Tools/ToolBar/toolBar.h"
#include <filesystem>
#include "../../windowManager/application.h"
#include <dlfcn.h>
#include "../Tools/PluginsTools/pluginsTools.h"
#include "../consts.h"

namespace Fs = std::filesystem;

class PluginManager {
private:
    static std::list<PlugTool*> plugToolsList;
    static std::list<void*> handlesList;

    static void linkPlugin(Fs::path pluginDir, 
                           Application& app, 
                           ToolBar& toolBar);
    static void linkSOFile(Fs::path soFile, 
                           Fs::path iconFile, 
                           ToolBar& toolBar);
    static void addIcon(Fs::path iconFile, Application& app);

public:
    static void addPlugins(const std::string& pluginDirPath,
                           Application& app, ToolBar& toolBar);

    static void closeAllPlugins();
};

#endif