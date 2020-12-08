#include "thickSlider.h"

ThickSlider::ThickSlider(int x, int y, int width, int height,
                         const Color& color, 
                         SystemEventSender* systemEventSender, 
                         int minPos, int maxPos, 
                         bool vertical):
    Slider(x, y, width, height, color, systemEventSender,
           minPos, maxPos, vertical) {}

void ThickSlider::onMouseMove(std::unique_ptr<Event>& event) {
    Slider::onMouseMove(event);

    ToolManager::changeThickness(minThickness + value * (maxThickness - minThickness));
}

void ThickSlider::setThicknessRange(int minThick, int maxThick) {
    minThickness = minThick;
    maxThickness = maxThick;
}


ThickSliderContainer::ThickSliderContainer(int x, int y, 
                         int width, int height,
                         const Color& color, 
                         SystemEventSender* systemEventSender, 
                         int minPos, int maxPos, 
                         bool vertical):
    thickSlider(x, y, width, height, color, systemEventSender,
                minPos, maxPos, vertical),
    RectangleWindow(minPos, y + height / 2 - 3, 
                    maxPos - minPos, 6, {0, 0, 0}) {
    addSubWindow(&thickSlider);
}

void ThickSliderContainer::setRailColor(const Color& newColor) {
    color = newColor;
}

void ThickSliderContainer::setThicknessRange(int minThick, int maxThick) {
    thickSlider.setThicknessRange(minThick, maxThick);
}
