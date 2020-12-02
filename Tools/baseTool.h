#ifndef BASETOOL_GRAPHICEDITOR_H
#define BASETOOL_GRAPHICEDITOR_H

#include "../../windowManager/application.h"

class Tool {
public:
    Tool() = default;
    virtual void setUp() = 0;
    virtual void drawStart(Window* canvas, int x, int y) = 0;
    virtual void drawEnd(Window* canvas, int x, int y) = 0;
    virtual void paint(Window* canvas, int x, int y) = 0;
};


#endif