#include "tools.h"

Pencil::Pencil(const Color& color, int thickness):
    color(color),
    thickness(thickness),
    lastMovePoint(-1, -1) {}

void Pencil::drawLine(int x1, int y1, int x2, int y2, 
                      Canvas* canvas) {
    int leftX = std::min(x1, x2);
    int leftY = leftX == x1 ? y1 : y2;
    int rightX = std::max(x1, x2);
    int rightY = rightX == x2 ? y2: y1;

    double x = leftX;
    double y = leftY;
    int step = std::max(rightX - leftX, std::abs(rightY - leftY)) + 1;

    double dx = (rightX - leftX) / static_cast<double>(step);
    double dy = (rightY - leftY) / static_cast<double>(step);
    for (int i = 0; i < step; ++i) {
        x += dx;
        y += dy;

        if (x > 0 && x < canvas->width && y > 0 && y < canvas->height) {
            canvas->getPixels()[y][x] = color;
        }
    }
}

void Pencil::drawStart(Window* canvas, int x, int y) {
    dynamic_cast<Canvas*>(canvas)->getPixels()[y][x] = color;
    lastMovePoint = {-1, -1};
}

void Pencil::drawEnd(Window* canvas, int x, int y) {}

void Pencil::paint(Window* canvas, int x, int y) {
    auto castCanvas = dynamic_cast<Canvas*>(canvas);

    if (lastMovePoint == Point(-1, -1)) {
        castCanvas->getPixels()[y][x] = color;
        lastMovePoint = {x, y};
    }
    else {
        drawLine(lastMovePoint.x, lastMovePoint.y, x, y, castCanvas);
        lastMovePoint = {x, y};
    }
}


Eraser::Eraser(const Color& color, int thickness):
    Pencil(color, thickness) {}
