#include "pluginManager.h"
// #include <iostream>

void PluginManager::addPlugins(const std::string& pluginDirPath, 
                               Application& app) {
    // Fs::path workdir = pluginDirPath;

    for (auto& pluginDir: Fs::directory_iterator(pluginDirPath)) {
        linkPlugin(pluginDir.path(), app);
    }
}

void PluginManager::linkPlugin(Fs::path pluginDir, Application& app) {
    std::string filePath;
    Fs::path soFile;
    Fs::path iconFile;

    for (auto& file: Fs::directory_iterator(pluginDir)) {
        filePath = file.path().string();

        if (filePath.ends_with(".so")) 
            soFile = file.path();
        
        if (filePath.ends_with(".png"))
            iconFile = file.path();
    }

    addIcon(iconFile, app);
    linkSOFile(soFile, iconFile);
}

void PluginManager::linkSOFile(Fs::path soFile, Fs::path iconFile) {

}

void PluginManager::addIcon(Fs::path iconFile, Application& app) {
    app.loadImageFromFile(iconFile.string(), iconFile.string());
}
