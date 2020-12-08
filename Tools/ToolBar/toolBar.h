#ifndef TOOLBAR_GRAPHICEDITOR_H
#define TOOLBAR_GRAPHICEDITOR_H

#include "../../../windowManager/application.h"
#include "../../Events/events.h"
#include "../ToolManager/toolManager.h"

class ToolBar: public RectangleWindow {
private:
    int toolSize = 40;
    int toolNum = 0;
    Color activeToolColor;
    SystemEventSender* systemEventSender;

    void sendToolNumEvent(std::unique_ptr<Event>& event);
    void sendToolButtonChangeColorEvent(std::unique_ptr<Event>& event);

public:
    ToolBar(int x, int y, int width, int height, 
            const Color& color, 
            SystemEventSender* systemEventSender,
            int toolIconSize, 
            const Color& activeToolColor);

    void addTool(const std::string_view& name, 
                 const Color& color,
                 const std::string& iconName);

    void getEvent(std::unique_ptr<Event>& event) override;
};

class ToolButton: public RectButton {
private:
    Color pressedColor;
    Color defaultColor;
public:
    ToolButton(int x, int y, int width, int height, 
               const Color& color, 
               SystemEventSender* systemEventSender,
               const std::string& iconName,
               const Color& pressedColor);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;

    void getEvent(std::unique_ptr<Event>& event) override;
};

class ToolBarInitializer {
public:
    ToolBarInitializer() = delete;

    static void addToolToToolBar(
                ToolBar* toolBar, Tool* tool, 
                const std::string_view& name, 
                const Color& color,
                const std::string& iconName = "");
};

#endif