#include "toolManager.h"

std::unordered_map<Window*, std::vector<Tool*>> ToolManager::tools;
Tool* ToolManager::activeTool;
Color ToolManager::activeColor;
int ToolManager::activeThickness;

void ToolManager::addTool(Window* toolBar, Tool* tool) {
    tools[toolBar].push_back(tool);
}

void ToolManager::addToolBar(Window* toolBar) {
    tools.insert({toolBar, {}});
}

void ToolManager::sendToolNum(Window* toolBar, int num) {
    setActiveTool(tools[toolBar][num]);
}

Tool* ToolManager::getActiveTool() {
    return activeTool;
}

void ToolManager::setActiveTool(Tool* tool) {
    activeTool = tool;
    tool->setUp();
} 

void ToolManager::changeColor(const Color& color) {
    ToolManager::activeColor = color;
}

void ToolManager::changeThickness(int thickness) {
    ToolManager::activeThickness = thickness;
}

Color& ToolManager::getColor() {
    return activeColor;
}

int ToolManager::getThickness() {
    return activeThickness;
}
