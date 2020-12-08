#include "toolBar.h"

ToolBar::ToolBar(int x, int y, int width, int height, 
            const Color& color, 
            SystemEventSender* systemEventSender,
            int ToolIconSize, 
            const Color& activeToolColor):
            RectangleWindow(x, y, width, height, color),
            systemEventSender(systemEventSender),
            toolSize(ToolIconSize),
            activeToolColor(activeToolColor) {

            EventManager::addSender(this);                
}

void ToolBar::addTool(const std::string_view& name,
                      const Color& color,
                      const std::string& iconName) {
    
    subWindows.push_back(new ToolButton(x + 5, y + toolNum * toolSize + 5, 
                         toolSize - 10, toolSize - 10, 
                         color, systemEventSender,
                         iconName, 
                         activeToolColor));
    
    if (0 == toolNum) {
        dynamic_cast<ToolButton*>(subWindows.back())->color = activeToolColor;
    }

    EventManager::addSender(subWindows.back());
    EventManager::addListener(subWindows.back(), this);
    EventManager::addListener(this, subWindows.back());

    ++toolNum;
}

void ToolBar::sendToolNumEvent(std::unique_ptr<Event>& event) {
    int eventNum = 
        (dynamic_cast<ToolButtonClickEvent*>(event.get())->pos - y) / toolSize;
    
    ToolManager::sendToolNum(this, eventNum);
}

void ToolBar::sendToolButtonChangeColorEvent(std::unique_ptr<Event>& event) {
    auto changeColorEvent = new ToolButtonChangeColorEvent;

    auto uniquePtrEvent = std::unique_ptr<Event>(changeColorEvent);
    EventManager::sendEvent(this, uniquePtrEvent);
}

void ToolBar::getEvent(std::unique_ptr<Event>& event) {
    switch (event->type) {
    case EditorEvent::ToolButtonClicked:
        sendToolNumEvent(event);
        sendToolButtonChangeColorEvent(event);
        break;
    
    default:
        break;
    }
}


ToolButton::ToolButton(int x, int y, int width, int height, 
                       const Color& color, 
                       SystemEventSender* systemEventSender, 
                       const std::string& iconName, 
                       const Color& pressedColor): 
    RectButton(x, y, width, height, color, 
               systemEventSender, iconName),
               pressedColor(pressedColor), 
               defaultColor(color) {}

void ToolButton::onLeftClick(std::unique_ptr<Event>& event) {
    auto toolButtonEvent = new ToolButtonClickEvent;
    toolButtonEvent->pos = dynamic_cast<MouseEvent*>(event.get())->y;

    auto uniquePtrEvent = std::unique_ptr<Event>(toolButtonEvent);
    EventManager::sendEvent(this, uniquePtrEvent);

    color = pressedColor;
}

void ToolButton::onLeftUnclick(std::unique_ptr<Event>& event) {}

void ToolButton::getEvent(std::unique_ptr<Event>& event) {
    RectButton::getEvent(event);

    switch (event->type) {
    case EditorEvent::ToolButtonChangeColor:
        color = defaultColor;
        break;
    
    default:
        break;
    }
}

void ToolBarInitializer::addToolToToolBar(
                ToolBar* toolBar, Tool* tool, 
                const std::string_view& name, 
                const Color& color,
                const std::string& iconName) {
    
    toolBar->addTool(name, color, iconName);
    ToolManager::addTool(toolBar, tool);
}