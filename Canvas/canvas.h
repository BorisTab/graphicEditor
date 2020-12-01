#ifndef GRAPHICEDITOR_CANVAS_H
#define GRAPHICEDITOR_CANVAS_H

#include "../../windowManager/application.h"
#include "../Tools/ToolManager/toolManager.h"


class Canvas: public RectButton {
private:
    std::vector<std::vector<Color>> pixels;
    bool mousePressed = false;
    // Point lastMovePoint;

public:
    Canvas(int x, int y, int width, int height, 
           const Color& color, SystemEventSender* systemEventSender);

    std::vector<std::vector<Color>>& getPixels();

    void draw(Engine& engine) override;
    
    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
    void getEvent(std::unique_ptr<Event> &event) override;
};
#endif //GRAPHICEDITOR_CANVAS_H
