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

void ColorPickerHue::onLeftClick(std::unique_ptr<Event>& event) {}

void ColorPickerHue::onLeftUnclick(std::unique_ptr<Event>& event) {}


ColorPickerSV::ColorPickerSV(int x, int y, int width, int height, 
                    const Color& color, 
                    SystemEventSender* systemEventSender):
    RectPixelButton(x, y, width, height, color, systemEventSender) {
    
    for (int yStart = 0; yStart < height; ++yStart) {
        int valueVal = 255 * yStart / height;

        for (int xStart = 0; xStart < width; ++xStart) {
            int saturationVal = 255 * xStart / width;
            Color color = Hsv::hsvToColor(0, saturationVal, valueVal);
            pixels[height - yStart - 1][xStart] = color;
        }
    }
}

void ColorPickerSV::onLeftClick(std::unique_ptr<Event>& event) {}

void ColorPickerSV::onLeftUnclick(std::unique_ptr<Event>& event) {}