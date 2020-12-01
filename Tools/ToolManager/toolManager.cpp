#include "toolManager.h"

std::unordered_map<Window*, std::vector<Tool*>> ToolManager::tools;
Tool* ToolManager::activeTool;

void ToolManager::addTool(Window* toolBar, Tool* tool) {
    tools[toolBar].push_back(tool);
}

void ToolManager::addToolBar(Window* toolBar) {
    tools.insert({toolBar, {}});
}

void ToolManager::sendToolNum(Window* toolBar, int num) {
    activeTool = tools[toolBar][num];
}

Tool* ToolManager::getActiveTool() {
    return activeTool;
}

void ToolManager::setActiveTool(Tool* tool) {
    activeTool = tool;
} 
