#include "pluginsTools.h"

PlugTool::PlugTool(PluginAPI::Plugin* plugin):
    plugin(plugin) {}

PlugTool::~PlugTool() {
    plugin->deinit();
}

void PlugTool::setUp() {}
void PlugTool::drawStart(Window* canvas, int x, int y) {
    setProperties();

    auto myCanvas = dynamic_cast<Canvas*>(canvas);
    auto pixels = myCanvas->getPixels();
    uint32_t plugCanvas[pixels.size()][pixels[0].size()];

    pixelsToPlugCanvas(pixels, *plugCanvas);

    plugin->start_apply({reinterpret_cast<uint8_t*>(*plugCanvas), pixels.size() * 4, pixels[0].size() * 4},
                        {x, y});

    myCanvas->setPixels(*plugCanvas, pixels[0].size(), pixels.size());
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
            plugCanvas[width * y + x] = pixels[y][x].getUint32();
        }
    }
}

void PlugTool::setProperties() {
    for (auto& prop: plugin->properties) {
        if (PluginAPI::Property::PRIMARY_COLOR == prop.first) 
            prop.second.int_value = ToolManager::getColor().getUint32();
        
        if (PluginAPI::Property::SECONDARY_COLOR == prop.first)
            prop.second.int_value = 0xffffffff;
        
        if (PluginAPI::Property::THICKNESS == prop.first)
            prop.second.int_value = ToolManager::getThickness();
    }
}
