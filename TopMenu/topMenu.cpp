#include "topMenu.h"

TopMenu::TopMenu(int x, int y, int width, int height, 
                 const Color& color, 
                 SystemEventSender* systemEventSender, 
                 const Color& buttonPressedColor):
    RectangleWindow(x, y, width, height, color),
    systemEventSender(systemEventSender),
    saveButton(0, 0, 40, 20, darkGrey, 
               systemEventSender, buttonPressedColor) {
    
    addSubWindow(&saveButton);
    EventManager::addSender(this);
    EventManager::addListener(&saveButton, this);
}

void TopMenu::getEvent(std::unique_ptr<Event>& event) {
    RectangleWindow::getEvent(event);

    switch (event->type)
    {
    case EditorEvent::SaveButtonClicked:
        EventManager::sendEvent(this, event);
        break;
    
    default:
        break;
    }
}

SaveButton::SaveButton(int x, int y, int width, int height, 
                       const Color& color, 
                       SystemEventSender* systemEventSender, 
                       const Color& pressedColor):
    RectButton(x, y, width, height, color, systemEventSender),
    buttonText(5, 2, "Save", "JosefinSans", 14, whiteColor),
    defaultColor(color),
    pressedColor(pressedColor) {
    
    addSubWindow(&buttonText);
    EventManager::addSender(this);
}

void SaveButton::onLeftClick(std::unique_ptr<Event>& event) {
    color = pressedColor;

    auto saveClickedEvent = new SaveButtonClickEvent;
    auto uniquePtrEvent = std::unique_ptr<Event>(saveClickedEvent);
    EventManager::sendEvent(this, uniquePtrEvent);
}
void SaveButton::onLeftUnclick(std::unique_ptr<Event>& event) {
    color = defaultColor;
}
