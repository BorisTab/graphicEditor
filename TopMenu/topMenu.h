#ifndef TOPMENU_GRAPHICEDITOR_H
#define TOPMENU_GRAPHICEDITOR_H

#include "../../windowManager/application.h"
#include "../consts.h"
#include "../Events/events.h"

class SaveButton: public RectButton {
private:
    Text buttonText;
    Color pressedColor;
    Color defaultColor;
public:
    SaveButton(int x, int y, int width, int height, const Color& color, 
               SystemEventSender* systemEventSender, 
               const Color& pressedColor);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
};

class TopMenu: public RectangleWindow {
private:
    SystemEventSender* systemEventSender;
    Color buttonPressedColor;

    SaveButton saveButton;

public:
    TopMenu(int x, int y, int width, int height, const Color& color, 
            SystemEventSender* systemEventSender, 
            const Color& buttonPressedColor);

    void getEvent(std::unique_ptr<Event>& event) override;
};

#endif