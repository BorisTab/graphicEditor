#ifndef COLORPICKER_GRAPHICEDITOR_H
#define COLORPICKER_GRAPHICEDITOR_H

#include "../../windowManager/application.h"
#include "../Hsv/hsv.h"
#include "../Events/events.h"
#include "../Tools/ToolManager/toolManager.h"
#include "../consts.h"

class HueSlider: public Slider {
public:
    HueSlider(int x, int y, int width, int height,
              const Color& color, 
              SystemEventSender* systemEventSender, 
              int minPos, int maxPos, 
              bool vertical = false);

    void getEvent(std::unique_ptr<Event>& event) override;
};

class SVPointer: public Pointer {
public:
    SVPointer(int x, int y, int width, int height,
             const Color& color, 
             SystemEventSender* systemEventSender, 
             int minX, int maxX, 
             int minY, int maxY);

    void getEvent(std::unique_ptr<Event>& event) override;
};

class ColorPickerHue: public RectPixelButton {
private:
    HueSlider slider;

public:
    ColorPickerHue(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
    void getEvent(std::unique_ptr<Event>& event) override;

    void sendHue(int clickY);
    void sendPos(int x, int y);
};

class ColorPickerSV: public RectPixelButton {
private:
    SVPointer pointer;

    void changeHueEventHandler(std::unique_ptr<Event>& event);
    void pointerMovedHandler(std::unique_ptr<Event>& event);

public:
    ColorPickerSV(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender);

    void onLeftClick(std::unique_ptr<Event>& event) override;
    void onLeftUnclick(std::unique_ptr<Event>& event) override;
    void getEvent(std::unique_ptr<Event>& event) override;

    void changePalette(int hue);
    void sendSV(int clickX, int clickY);
    void sendPos(int x, int y);
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