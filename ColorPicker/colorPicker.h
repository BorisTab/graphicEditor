#ifndef COLORPICKER_GRAPHICEDITOR_H
#define COLORPICKER_GRAPHICEDITOR_H

#include "../../windowManager/application.h"
#include "../Hsv/hsv.h"
#include "../Events/events.h"
#include "../Tools/ToolManager/toolManager.h"

class ColorPickerHue: public RectPixelButton {
public:
    ColorPickerHue(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
};

class ColorPickerSV: public RectPixelButton {
private:
    void changeHueEventHandler(std::unique_ptr<Event>& event);

public:
    ColorPickerSV(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
    void getEvent(std::unique_ptr<Event>& event) override;

    void changePalette(int hue);
};

class ColorPicker: public RectangleWindow {
private:
    ColorPickerHue colorPickerHue;
    ColorPickerSV colorPickerSV;
    Hsv::HsvColor currentColor;

    void changeHueEventHandler(std::unique_ptr<Event>& event);
    void changeSVEventHandler(std::unique_ptr<Event>& event);

public:
    ColorPicker(int x, int y, int width, int height, 
                const Color& color, int border, int hueWidth, 
                SystemEventSender* systemEventSender);

    void getEvent(std::unique_ptr<Event>& event) override;
};

#endif