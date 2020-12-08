#ifndef GRAPHICEDITOR_CONSTS_H
#define GRAPHICEDITOR_CONSTS_H

#include "../windowManager/application.h"

const Color darkBlue(65, 74, 105);
const Color canvasColor(255, 255, 255);
const Color blackColor(0, 0, 0);
const Color whiteColor(255, 255, 255);
const Color darkGrey(38, 34, 34);
const Color lightGrey(187, 187, 187);

constexpr int windowWidth = 1915;
constexpr int windowHeight = 1080 - 55;

constexpr int canvasHeight = 900;
constexpr double canvasWidthCoeff = 1.41;

constexpr int canvasStartX = 50;
constexpr int canvasStartY = 50;

#endif //GRAPHICEDITOR_CONSTS_H
