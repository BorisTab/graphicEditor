#include "../include/BoxBlur.hpp"

bool BoxBlur::init() {
    properties[PluginAPI::TYPE::THICKNESS].display_type = 
        PluginAPI::Property::DISPLAY_TYPE::SLIDER;

    return true;
}

bool BoxBlur::deinit() {
    return true;
}

void BoxBlur::start_apply(PluginAPI::Canvas canvas, PluginAPI::Position pos) {
    size_t width = canvas.width;
    size_t height = canvas.height;
    size_t radius = properties[PluginAPI::TYPE::THICKNESS].int_value / 2;

    uint32_t oldPixels[height * width];
    for (uint32_t y = 0; y < height; ++y) {
        for (uint32_t x = 0; x < width; ++x) {
            oldPixels[y * width + x] = canvas.pixels[(y * width + x) * 4];
        }
    }

    for (uint32_t pos = width * radius; pos < height * width - width * radius; ++pos) {
        if (pos % width < radius || width - radius >= pos % width)
            continue;

        uint32_t colorSum[4] = {};

        for(uint32_t y = pos / width - radius; y < pos / width + radius; ++y) {
            for (uint32_t x = pos - radius; x < pos + radius; ++x) {
                uint32_t color = oldPixels[y * width + x];

                colorSum[0] += (color >> 24) & 0xff;
                colorSum[1] += (color >> 16) & 0xff;
                colorSum[2] += (color >>  8) & 0xff;
                colorSum[3] +=  color        & 0xff;
            }
        }

        for (auto& sum: colorSum) {
            sum /= radius * radius;
        }

        for (int i = pos; i < 4; ++i) {
            canvas.pixels[i] = static_cast<uint8_t> (colorSum[i]);
        }
    }
}


void BoxBlur::apply(PluginAPI::Canvas canvas, PluginAPI::Position pos) {}
void BoxBlur::stop_apply(PluginAPI::Canvas canvas, PluginAPI::Position pos) {}

extern "C" PluginAPI::Plugin* get_plugin() {
    return PluginAPI::get_instance<BoxBlur>();
}
