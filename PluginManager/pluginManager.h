#ifndef PLUGINMANAGER_GRAPHICEDITOR_H
#define PLUGINMANAGER_GRAPHICEDITOR_H

#include "../Tools/ToolBar/toolBar.h"
#include <filesystem>
#include "../../windowManager/application.h"

namespace Fs = std::filesystem;

class PluginManager {
private:
    static void linkPlugin(Fs::path pluginDir, Application& app);
    static void linkSOFile(Fs::path soFile, Fs::path iconFile);
    static void addIcon(Fs::path iconFile, Application& app);
public:
    static void addPlugins(const std::string& pluginDirPath, Application& app);
};

#endif