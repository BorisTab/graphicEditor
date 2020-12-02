#include "hsv.h"

Color Hsv::hsvToColor(uint16_t hue, uint8_t saturation, uint8_t value) {
    Color color;

    HsvConverter::getRgbFromHSV(hue, saturation, value, color.r, color.g, color.b);
    return color;
}

Hsv::HsvColor Hsv::ColorToHsv(const Color& color) {
    Hsv::HsvColor hsvColor;
    HsvConverter::RGBtoHSV(color.r, color.g, color.b, 
                           hsvColor.h, hsvColor.s, hsvColor.v);
    
    return hsvColor;
}

Hsv::HsvColor::HsvColor(int h, int s, int v): h(h), s(s), v(v) {}