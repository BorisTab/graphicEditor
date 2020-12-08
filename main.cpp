#include "../windowManager/application.h"
#include "consts.h"
#include "Canvas/canvas.h"
#include "Tools/ToolBar/toolBar.h"
#include "Tools/tools.h"
#include "ColorPicker/colorPicker.h"
#include "VisualOptions/thickSlider/thickSlider.h"

int main() {
    Application graphicEditor(windowWidth - 10, windowHeight, "Graphic Editor");
    graphicEditor.setBackgroundColor(backgroundColor);

    Canvas canvas(canvasStartX, canvasStartY, canvasHeight * canvasWidthCoeff,
                  canvasHeight, canvasColor,
                  graphicEditor.getSystemEventManager());
    graphicEditor.addDrawableObject(&canvas);

    ToolBar toolBar(5, canvasStartY, canvasStartX - 5 - 5, windowHeight - canvasStartY - 5, darkGrey,
                    graphicEditor.getSystemEventManager(), canvasStartX - 5 - 5);
    graphicEditor.addDrawableObject(&toolBar);

    Pencil pencil(blackColor, 10);
    Eraser eraser(whiteColor, 10);

    ToolBarInitializer::addToolToToolBar(&toolBar,
                                         &pencil,
                                         "Pencil",
                                         whiteColor,
                                         "");

    ToolBarInitializer::addToolToToolBar(&toolBar,
                                         &eraser,
                                         "Eraser",
                                         whiteColor,
                                         "");
    ToolManager::setActiveTool(&pencil);

    ColorPicker colorPicker(1400, canvasStartY, 355, 300, darkGrey,
                            25, 30, 
                            graphicEditor.getSystemEventManager());
    graphicEditor.addDrawableObject(&colorPicker);

    ThickSliderContainer thicknessSlider(1500, canvasStartY + 300 + 20, 6, 40, whiteColor, 
                                graphicEditor.getSystemEventManager(), 1400, 1400 + 355);
    thicknessSlider.setRailColor(darkGrey);
    thicknessSlider.setThicknessRange(1, 30);
    graphicEditor.addDrawableObject(&thicknessSlider);

    graphicEditor.run();
    return 0;
}
