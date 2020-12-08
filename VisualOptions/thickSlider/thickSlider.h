#ifndef THICKSLIDER_GRAPHICEDITOR_H
#define THICKSLIDER_GRAPHICEDITOR_H

#include "../../../windowManager/application.h"
#include "../../Tools/ToolManager/toolManager.h"

class ThickSlider: public Slider {
private:
    // RectangleWindow rail;
    int minThickness = 1;
    int maxThickness = 20;

public:
    ThickSlider(int x, int y, int width, int height,
                const Color& color, 
                SystemEventSender* systemEventSender, 
                int minPos, int maxPos, 
                bool vertical = false);
    
    void setThicknessRange(int minThick, int maxThick);
    
    void onMouseMove(std::unique_ptr<Event>& event) override;
};

class ThickSliderContainer: public RectangleWindow {
private:
    ThickSlider thickSlider;

public:
    ThickSliderContainer(int x, int y, int width, int height,
                         const Color& color, 
                         SystemEventSender* systemEventSender, 
                         int minPos, int maxPos, 
                         bool vertical = false);
    
    void setRailColor(const Color& newColor);
    void setThicknessRange(int minThick, int maxThick);
};

#endif