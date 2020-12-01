#include "canvas.h"

Canvas::Canvas(int x, int y, int width, int height, 
               const Color &color, SystemEventSender* systemEventSender):
    RectButton(x, y, width, height, color, systemEventSender),
    pixels(height, std::vector<Color>(width, color)) {}

void Canvas::draw(Engine &engine) {
    engine.drawPixels(x, y, pixels);
}

void Canvas::onLeftClick(std::unique_ptr<Event>& event) {
    int clickX = dynamic_cast<MouseEvent*>(event.get())->x;
    int clickY = dynamic_cast<MouseEvent*>(event.get())->y;

    mousePressed = true;
    ToolManager::getActiveTool()->drawStart(this, clickX - x, clickY - y);
}

void Canvas::onLeftUnclick(std::unique_ptr<Event>& event) {
    mousePressed = false;
}

void Canvas::getEvent(std::unique_ptr<Event> &event) {
    if (event->type == Event::MouseMoved && mousePressed) {
        int clickX = dynamic_cast<MouseEvent*>(event.get())->x;
        int clickY = dynamic_cast<MouseEvent*>(event.get())->y;

        (ToolManager::getActiveTool())->paint(this, clickX - x, clickY - y);
    }

    RectButton::getEvent(event);
}

std::vector<std::vector<Color>>& Canvas::getPixels() {
    return pixels;
}
