#include "../windowManager/application.h"
#include "consts.h"
#include "Canvas/canvas.h"
#include "Tools/ToolBar/toolBar.h"
#include "Tools/tools.h"
#include "ColorPicker/colorPicker.h"

int main()
{
    Application graphicEditor(windowWidth, windowHeight, "Graphic Editor");
    graphicEditor.setBackgroundColor(backgroundColor);

    Canvas canvas(canvasStartX, canvasStartY, canvasHeight * canvasWidthCoeff,
                  canvasHeight, canvasColor,
                  graphicEditor.getSystemEventManager());
    graphicEditor.addDrawableObject(&canvas);

    ToolBar toolBar(5, canvasStartY, canvasStartX - 5 - 5, windowHeight - canvasStartY - 5, {38, 34, 34},
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

    RectangleWindow colorPicker(1400, canvasStartY, 
                                50 + 250 + 30 + 25, 300, {38, 34, 34});
    graphicEditor.addDrawableObject(&colorPicker);

    ColorPickerHue colorPickerHue(1700, canvasStartY + 25, 
                                  30, 250, whiteColor,
                                  graphicEditor.getSystemEventManager());
    colorPicker.addSubWindow(&colorPickerHue);

    ColorPickerSV colorPickerSV(1425, canvasStartY + 25, 
                                  250, 250, whiteColor,
                                  graphicEditor.getSystemEventManager());
    colorPicker.addSubWindow(&colorPickerSV);

    graphicEditor.run();
    return 0;
}
