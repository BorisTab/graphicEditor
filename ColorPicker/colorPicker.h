#ifndef COLORPICKER_GRAPHICEDITOR_H
#define COLORPICKER_GRAPHICEDITOR_H

#include "../../windowManager/application.h"
#include "../Hsv/hsv.h"

class ColorPickerHue: public RectPixelButton {
public:
    ColorPickerHue(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
};

class ColorPickerSV: public RectPixelButton {
public:
    ColorPickerSV(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
};



#endif