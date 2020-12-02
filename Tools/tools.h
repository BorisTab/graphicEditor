#ifndef GRAPHICEDITOR_TOOLS_H
#define GRAPHICEDITOR_TOOLS_H

#include "baseTool.h"
#include "../Canvas/canvas.h"

class Pencil: public Tool {
protected:
    Color color;
    int thickness = 0;
    Point lastMovePoint;

    void drawLine(int x1, int y1, int x2, int y2, Canvas* canvas);
    void drawPoint(int x, int y, Canvas* canvas);

public:
    Pencil(const Color& color, int thickness);

    void setUp() override; 
    void drawStart(Window* canvas, int x, int y) override;
    void drawEnd(Window* canvas, int x, int y) override;
    void paint(Window* canvas, int x, int y) override;

    void setColor(const Color& newColor);
    void setThickness(int newThickness);
};

class Eraser: public Pencil {
public:
    Eraser(const Color& color, int thickness);

    void drawStart(Window* canvas, int x, int y) override;
};

#endif //GRAPHICEDITOR_TOOLS_H
