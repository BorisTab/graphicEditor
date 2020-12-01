#include "../windowManager/application.h"
#include "consts.h"
#include "Canvas/canvas.h"
#include "Tools/ToolBar/toolBar.h"
#include "Tools/tools.h"

int main()
{
    Application graphicEditor(windowWidth, windowHeight, "Graphic Editor");
    graphicEditor.setBackgroundColor(backgroundColor);

    Canvas canvas(canvasStartX, canvasStartY, canvasHeight * canvasWidthCoeff,
                  canvasHeight, canvasColor,
                  graphicEditor.getSystemEventManager());
    graphicEditor.addDrawableObject(&canvas);

    ToolBar toolBar(5, canvasStartY, canvasStartX - 5 - 5, windowHeight - 10, {38, 34, 34},
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

    graphicEditor.run();
    return 0;
}
