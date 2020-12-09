#include "pluginsTools.h"

PlugTool::PlugTool(PluginAPI::Plugin* plugin):
    plugin(plugin) {
    plugin->init();
}

PlugTool::~PlugTool() {
    plugin->deinit();
}

void PlugTool::setUp() {}
void PlugTool::drawStart(Window* canvas, int x, int y) {
    setProperties();

    auto myCanvas = dynamic_cast<Canvas*>(canvas);
    auto pixels = myCanvas->getPixels();
    size_t width = pixels[0].size();
    size_t height = pixels.size();
    uint32_t plugPixels[height * width];

    pixelsToPlugCanvas(pixels, plugPixels);

    plugin->start_apply({reinterpret_cast<uint8_t*>(plugPixels), height, width},
                        {x, y});

    myCanvas->setPixels(plugPixels, pixels[0].size(), pixels.size());
}
void PlugTool::drawEnd(Window* canvas, int x, int y) {
    auto myCanvas = dynamic_cast<Canvas*>(canvas);
    auto pixels = myCanvas->getPixels();
    uint32_t plugCanvas[pixels.size()][pixels[0].size()];

    pixelsToPlugCanvas(pixels, *plugCanvas);

    plugin->stop_apply({reinterpret_cast<uint8_t*>(*plugCanvas), pixels.size() * 4, pixels[0].size() * 4},
                        {x, y});

    myCanvas->setPixels(*plugCanvas, pixels[0].size(), pixels.size());
}

void PlugTool::paint(Window* canvas, int x, int y) {
    auto myCanvas = dynamic_cast<Canvas*>(canvas);
    auto pixels = myCanvas->getPixels();
    uint32_t plugCanvas[pixels.size()][pixels[0].size()];

    pixelsToPlugCanvas(pixels, *plugCanvas);

    plugin->apply({reinterpret_cast<uint8_t*>(*plugCanvas), pixels.size() * 4, pixels[0].size() * 4},
                        {x, y});

    myCanvas->setPixels(*plugCanvas, pixels[0].size(), pixels.size());
}

void PlugTool::pixelsToPlugCanvas(std::vector<std::vector<Color>>& pixels, 
                            uint32_t* plugCanvas) {
    int width = pixels[0].size();

    for (int y = 0; y < pixels.size(); ++y) {
        for (int x = 0; x < width; ++x) {
            plugCanvas[width * y + x] = pixels[y][x].getBackUint32();
        }
    }
}

void PlugTool::setProperties() {
    for (auto& prop: plugin->properties) {
        if (PluginAPI::TYPE::PRIMARY_COLOR == prop.first) 
            prop.second.int_value = ToolManager::getColor().getBackUint32();
        
        else if (PluginAPI::TYPE::SECONDARY_COLOR == prop.first)
            prop.second.int_value = 0xffffffff;
        
        else if (PluginAPI::TYPE::THICKNESS == prop.first)
            prop.second.int_value = ToolManager::getThickness();
    }
}
