#ifndef GRAPHICEDITOR_CANVAS_H
#define GRAPHICEDITOR_CANVAS_H

#include "../../windowManager/application.h"
// #include <memory>

struct Point {
    int x = 0;
    int y = 0;

    Point(int x, int y);
};

class Canvas: public RectButton {
private:
    std::vector<std::vector<Color>> pixels;
    bool mousePressed = false;
    Point lastMovePoint;

    void drawLine(int x1, int y1, int x2, int y2, int radius, const Color& color);
public:
    Canvas(int x, int y, int width, int height, 
           const Color& color, SystemEventSender* systemEventSender);

    void draw(Engine& engine) override;
    
    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
    void getEvent(std::unique_ptr<Event> &event) override;
};
#endif //GRAPHICEDITOR_CANVAS_H
