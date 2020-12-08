#include "canvas.h"

Canvas::Canvas(int x, int y, int width, int height, 
               const Color &color, SystemEventSender* systemEventSender):
    RectPixelButton(x, y, width, height, color, systemEventSender) {

    EventManager::addSender(this);
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

void Canvas::saveCanvas() {
    std::string filePath = "/home/boris/Desktop/qqq.png";
    auto savePixelsEvent = new SavePixelsEvent(pixels, filePath);

    auto uniquePtrEvent = std::unique_ptr<Event>(savePixelsEvent);
    EventManager::sendEvent(this, uniquePtrEvent);
}

void Canvas::getEvent(std::unique_ptr<Event> &event) {
    if (event->type == Event::MouseMoved && mousePressed) {
        int clickX = dynamic_cast<MouseEvent*>(event.get())->x;
        int clickY = dynamic_cast<MouseEvent*>(event.get())->y;

        (ToolManager::getActiveTool())->paint(this, clickX - x, clickY - y);
    }
    else if (event->type == EditorEvent::SaveButtonClicked) {
        saveCanvas();
    }

    RectButton::getEvent(event);
}
