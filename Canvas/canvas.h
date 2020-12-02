#ifndef GRAPHICEDITOR_CANVAS_H
#define GRAPHICEDITOR_CANVAS_H

#include "../../windowManager/application.h"
#include "../Tools/ToolManager/toolManager.h"


class Canvas: public RectPixelButton {
private:
    bool mousePressed = false;

public:
    Canvas(int x, int y, int width, int height, 
           const Color& color, SystemEventSender* systemEventSender);
    
    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
    void getEvent(std::unique_ptr<Event> &event) override;
};
#endif //GRAPHICEDITOR_CANVAS_H
