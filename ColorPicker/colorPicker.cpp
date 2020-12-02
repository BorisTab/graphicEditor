#include "colorPicker.h"

ColorPickerHue::ColorPickerHue(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender):
    RectPixelButton(x, y, width, height, color, systemEventSender) {
    
    for (int yStart = 0; yStart < height; ++yStart) {
        int hueVal = Hsv::hueMax * yStart / height;

        Color color = Hsv::hsvToColor(hueVal, 255, 255);
        for (int xStart = 0; xStart < width; ++xStart) {
            pixels[height - yStart - 1][xStart] = color;
        }
    }
}

void ColorPickerHue::onLeftClick(std::unique_ptr<Event>& event) {
    int clickY = dynamic_cast<MouseEvent*>(event.get())->y;

    auto colorHue = new ChangeHueColorEvent;
    colorHue->hue = Hsv::hueMax * (height - clickY + y) / height;

    auto uniquePtrEvent = std::unique_ptr<Event>(colorHue);
    EventManager::sendEvent(this, uniquePtrEvent);
}

void ColorPickerHue::onLeftUnclick(std::unique_ptr<Event>& event) {}


ColorPickerSV::ColorPickerSV(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender):
    RectPixelButton(x, y, width, height, color, systemEventSender) {
    
    changePalette(0);
}

void ColorPickerSV::changePalette(int hue) {
    for (int yStart = 0; yStart < height; ++yStart) {
        int valueVal = 255 * yStart / height;

        for (int xStart = 0; xStart < width; ++xStart) {
            int saturationVal = 255 * xStart / width;
            Color color = Hsv::hsvToColor(hue, saturationVal, valueVal);
            pixels[height - yStart - 1][xStart] = color;
        }
    }
}

void ColorPickerSV::getEvent(std::unique_ptr<Event>& event) {
    switch (event->type) {
    case EditorEvent::ColorHueChanged:
        changeHueEventHandler(event);
        break;
    
    default:
        break;
    }

    RectPixelButton::getEvent(event);
}

void ColorPickerSV::changeHueEventHandler(std::unique_ptr<Event>& event) {
    int hue = dynamic_cast<ChangeHueColorEvent*>(event.get())->hue;
    changePalette(hue);
}


void ColorPickerSV::onLeftClick(std::unique_ptr<Event>& event) {
    int clickX = dynamic_cast<MouseEvent*>(event.get())->x;
    int clickY = dynamic_cast<MouseEvent*>(event.get())->y;

    auto colorSVEvent = new ChangeSVColorEvent;
    colorSVEvent->saturation = 255 * (clickX - x) / width;
    colorSVEvent->value = 255 * (height - clickY + y) / height;

    auto uniquePtrEvent = std::unique_ptr<Event>(colorSVEvent);
    EventManager::sendEvent(this, uniquePtrEvent);
}

void ColorPickerSV::onLeftUnclick(std::unique_ptr<Event>& event) {}


ColorPicker::ColorPicker(int x, int y, int width, int height, 
                         const Color& color, int border, int hueWidth, 
                         SystemEventSender* systemEventSender):
    RectangleWindow(x, y, width, height, color),
    colorPickerSV(x + border, y + border, 
                  height - 2 * border,
                  height - 2 * border,
                  color, 
                  systemEventSender),
    colorPickerHue(x + width - border - hueWidth,
                   y + border,
                   hueWidth,
                   height - 2 * border,
                   color, 
                   systemEventSender), 
    currentColor(0, 0, 0) {
    
    addSubWindow(&colorPickerHue);
    addSubWindow(&colorPickerSV);

    EventManager::addSender(&colorPickerHue);
    EventManager::addSender(&colorPickerSV);

    EventManager::addListener(&colorPickerHue, &colorPickerSV);
    EventManager::addListener(&colorPickerHue, this);
    EventManager::addListener(&colorPickerSV, this);
}

void ColorPicker::getEvent(std::unique_ptr<Event>& event) {
    switch (event->type) {
    case EditorEvent::ColorHueChanged:
        changeHueEventHandler(event);
        break;
    
    case EditorEvent::ColorSVChanged:
        changeSVEventHandler(event);
        break;

    default:
        break;
    }

    RectangleWindow::getEvent(event);
}

void ColorPicker::changeHueEventHandler(std::unique_ptr<Event>& event) {
    int hue = dynamic_cast<ChangeHueColorEvent*>(event.get())->hue;
    currentColor = {hue, currentColor.s, currentColor.v};

    ToolManager::changeColor(Hsv::hsvToColor(currentColor));
}

void ColorPicker::changeSVEventHandler(std::unique_ptr<Event>& event) {
    auto colorEvent = dynamic_cast<ChangeSVColorEvent*>(event.get());
    int saturation = colorEvent->saturation;
    int value = colorEvent->value;
    currentColor = {currentColor.h, saturation, value};

    ToolManager::changeColor(Hsv::hsvToColor(currentColor));
}
