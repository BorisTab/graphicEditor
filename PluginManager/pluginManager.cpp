#include "pluginManager.h"

std::list<PlugTool*> PluginManager::plugToolsList;
std::list<void*> PluginManager::handlesList;

void PluginManager::addPlugins(const std::string& pluginDirPath, 
                               Application& app, 
                               ToolBar& toolBar) {

    for (auto& pluginDir: Fs::directory_iterator(pluginDirPath)) {
        linkPlugin(pluginDir.path(), app, toolBar);
    }
}

void PluginManager::linkPlugin(Fs::path pluginDir, Application& app, 
                               ToolBar& toolBar) {
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
    linkSOFile(soFile, iconFile, toolBar);
}

void PluginManager::linkSOFile(Fs::path soFile, Fs::path iconFile, 
                               ToolBar& toolBar) {
    void* handle = dlopen(soFile.c_str(), RTLD_LAZY);
    handlesList.push_back(handle);

    auto getPlugin = 
        reinterpret_cast<PluginAPI::Plugin* (*) ()> (dlsym(handle, "get_plugin"));

    if (!getPlugin) {
        fprintf(stderr, "Can't connect plugin %s", soFile.c_str());
        return;
    }

    plugToolsList.push_back(new PlugTool((*getPlugin)()));

    ToolBarInitializer::addToolToToolBar(&toolBar, 
                                         plugToolsList.back(),     
                                         "", 
                                         whiteColor, 
                                         iconFile.string());
}

void PluginManager::addIcon(Fs::path iconFile, Application& app) {
    app.loadImageFromFile(iconFile.string(), iconFile.string());
}

void PluginManager::closeAllPlugins() {
    for (auto handle: handlesList) {
        dlclose(handle);
    }
}
