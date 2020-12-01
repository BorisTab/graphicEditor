#include "toolBar.h"

ToolBar::ToolBar(int x, int y, int width, int height, 
            const Color& color, 
            SystemEventSender* systemEventSender,
            int ToolIconSize):
            RectangleWindow(x, y, width, height, color),
            systemEventSender(systemEventSender),
            toolSize(ToolIconSize) {

            EventManager::addSender(this);                
}

void ToolBar::addTool(const std::string_view& name,
                      const Color& color,
                      const std::string_view& iconPath) {
    
    subWindows.push_back(new ToolButton(x + 5, y + toolNum * toolSize + 5, 
                         toolSize - 10, toolSize - 10, color, systemEventSender));

    EventManager::addSender(subWindows.back());
    EventManager::addListener(subWindows.back(), this);

    ++toolNum;
}

void ToolBar::sendToolNumEvent(std::unique_ptr<Event>& event) {
    int eventNum = 
        dynamic_cast<ToolButtonClickEvent*>(event.get())->pos / toolSize;
    
    ToolManager::sendToolNum(this, eventNum);
//     auto toolNumEvent = new ToolNumEvent();
//     toolNumEvent->toolNum = eventNum;

//     auto uniquePtrEvent = std::unique_ptr<Event>(toolNumEvent);
//     EventManager::sendEvent(this, uniquePtrEvent);
}

void ToolBar::getEvent(std::unique_ptr<Event>& event) {
    switch (event->type) {
    case EditorEvent::ToolButtonClicked:
        sendToolNumEvent(event);
        break;
    
    default:
        break;
    }
}


ToolButton::ToolButton(int x, int y, int width, int height, 
            const Color& color, 
            SystemEventSender* systemEventSender): 
            RectButton(x, y, width, height, color, systemEventSender) {}

void ToolButton::onLeftClick(std::unique_ptr<Event>& event) {
    auto toolButtonEvent = new ToolButtonClickEvent;
    toolButtonEvent->pos = dynamic_cast<MouseEvent*>(event.get())->y;

    auto uniquePtrEvent = std::unique_ptr<Event>(toolButtonEvent);
    EventManager::sendEvent(this, uniquePtrEvent);
}

void ToolButton::onLeftUnclick(std::unique_ptr<Event>& event) {}


void ToolBarInitializer::addToolToToolBar(
                ToolBar* toolBar, Tool* tool, 
                const std::string_view& name, 
                const Color& color,
                const std::string_view& iconPath) {
    
    toolBar->addTool(name, color, iconPath);
    ToolManager::addTool(toolBar, tool);
}