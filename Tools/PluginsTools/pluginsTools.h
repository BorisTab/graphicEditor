#ifndef PLUGINSTOOLS_GRAPHICEDITOR_H
#define PLUGINSTOOLS_GRAPHICEDITOR_H

#include "../baseTool.h"
#include "pluginsApi.h"
#include "../../Canvas/canvas.h"

class PlugTool: public Tool {
private:
    PluginAPI::Plugin* plugin;

    void pixelsToPlugCanvas(std::vector<std::vector<Color>>& pixels, 
                            uint32_t* plugCanvas);

    void setProperties();

public:
    PlugTool(PluginAPI::Plugin* plugin);

    void setUp() override;
    void drawStart(Window* canvas, int x, int y) override;
    void drawEnd(Window* canvas, int x, int y) override;
    void paint(Window* canvas, int x, int y) override;

    ~PlugTool();
};


#endif