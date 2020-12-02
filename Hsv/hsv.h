#ifndef HSV_GRAPHICEDITOR_H
#define HSV_GRAPHICEDITOR_H

#include "../../windowManager/application.h"
#include "HsvConverter/hsvConverter.h"

namespace Hsv {
    struct HsvColor {
        int h = 0;
        int s = 0;
        int v = 0;

        HsvColor() = default;
        HsvColor(int h, int s, int v);
    };
    
    constexpr int hueMax = 1529;
    Color hsvToColor(uint16_t hue, uint8_t saturation, uint8_t value);
    Color hsvToColor(const HsvColor& hsvColor);
    HsvColor ColorToHsv(const Color& color);
};

#endif