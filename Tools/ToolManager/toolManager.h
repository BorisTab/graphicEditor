#ifndef TOOLMANAGER_GRAPHICEDITOR_H
#define TOOLMANAGER_GRAPHICEDITOR_H

#include "../baseTool.h"

class ToolManager {
private:
    static std::unordered_map<Window*, std::vector<Tool*>> tools;
    static Tool* activeTool;
    static Color activeColor;
    static int activeThickness;

public:
    ToolManager() = delete;

    static void addToolBar(Window* toolBar);
    static void addTool(Window* toolBar, Tool* tool);

    static void sendToolNum(Window* toolBar, int num);

    static Tool* getActiveTool();
    static void setActiveTool(Tool* tool);

    static void changeColor(const Color& color);
    static void changeThickness(int thickness);
    static Color& getColor();
    static int getThickness();
};

#endif