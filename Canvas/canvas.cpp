#include "canvas.h"

Point::Point(int x, int y): x(x), y(y) {}

Canvas::Canvas(int x, int y, int width, int height, 
               const Color &color, SystemEventSender* systemEventSender):
    RectButton(x, y, width, height, color, systemEventSender),
    pixels(height, std::vector<Color>(width, color)),
    lastMovePoint(0, 0) {}

void Canvas::draw(Engine &engine) {
    engine.drawPixels(x, y, pixels);
}

void Canvas::onLeftClick(std::unique_ptr<Event>& event) {
    int clickX = dynamic_cast<MouseEvent*>(event.get())->x;
    int clickY = dynamic_cast<MouseEvent*>(event.get())->y;

    mousePressed = true;
    pixels[clickY - y][clickX - x] = Color(0, 0, 0);
    lastMovePoint = {clickX - x, clickY - y};
}

void Canvas::onLeftUnclick(std::unique_ptr<Event>& event) {
    mousePressed = false;
}

void Canvas::getEvent(std::unique_ptr<Event> &event) {
    if (event->type == Event::MouseMoved && mousePressed) {
        int clickX = dynamic_cast<MouseEvent*>(event.get())->x;
        int clickY = dynamic_cast<MouseEvent*>(event.get())->y;

//        pixels[clickY - y][clickX - x] = Color(0, 0, 0);
        drawLine(clickX - x, clickY - y, lastMovePoint.x, lastMovePoint.y,
                 1, {0, 0, 0});
        lastMovePoint = {clickX - x, clickY - y};
    }

    RectButton::getEvent(event);
}

void Canvas::drawLine(int x1, int y1, int x2, int y2, int radius, const Color& color) {
    int leftX = std::min(x1, x2);
    int leftY = leftX == x1 ? y1 : y2;
    int rightX = std::max(x1, x2);
    int rightY = rightX == x2 ? y2: y1;

    double x = leftX;
    double y = leftY;
    int step = std::max(rightX - leftX, std::abs(rightY - leftY)) + 1;

    double dx = (rightX - leftX) / static_cast<double>(step);
    double dy = (rightY - leftY) / static_cast<double>(step);
    for (int i = 0; i < step; ++i) {
        x += dx;
        y += dy;

        if (x > 0 && x < width && y > 0 && y < height) {
            pixels[y][x] = color;
        }
    }
}