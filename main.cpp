#include "../windowManager/application.h"
#include "consts.h"
#include "Canvas/canvas.h"
#include "Tools/ToolBar/toolBar.h"
#include "Tools/tools.h"
#include "ColorPicker/colorPicker.h"
#include "VisualOptions/thickSlider/thickSlider.h"
#include "TopMenu/topMenu.h"
#include "PluginManager/pluginManager.h"

int main() {
    Application graphicEditor(windowWidth - 10, windowHeight, "Graphic Editor");
    graphicEditor.setBackgroundColor(darkBlue);

    graphicEditor.loadImageFromFile("/home/boris/CLionProjects/graphicEditor/img/pen.png", 
                                    "penIcon");
    graphicEditor.loadImageFromFile("/home/boris/CLionProjects/graphicEditor/img/eraser.png", 
                                    "eraserIcon");
    
    graphicEditor.loadFontFromFile("/home/boris/CLionProjects/graphicEditor/fonts/JosefinSans-Regular.ttf", 
                                   "JosefinSans");

    Canvas canvas(canvasStartX, canvasStartY, canvasHeight * canvasWidthCoeff,
                  canvasHeight, canvasColor,
                  graphicEditor.getSystemEventManager());
    EventManager::addListener(&canvas, &graphicEditor);
    graphicEditor.addDrawableObject(&canvas);

    ToolBar toolBar(5, canvasStartY, canvasStartX - 5 - 5, windowHeight - canvasStartY - 5, darkGrey,
                    graphicEditor.getSystemEventManager(), 
                    canvasStartX - 5 - 5, 
                    lightGrey);
    graphicEditor.addDrawableObject(&toolBar);

    Pencil pencil(blackColor, 10);
    Eraser eraser(whiteColor, 10);

    ToolBarInitializer::addToolToToolBar(&toolBar,
                                         &pencil,
                                         "Pencil",
                                         whiteColor,
                                         "penIcon");

    ToolBarInitializer::addToolToToolBar(&toolBar,
                                         &eraser,
                                         "Eraser",
                                         whiteColor,
                                         "eraserIcon");
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

    TopMenu topMenu(0, 0, windowWidth, 20, darkGrey, 
                    graphicEditor.getSystemEventManager(), lightGrey);
    EventManager::addListener(&topMenu, &canvas);
    graphicEditor.addDrawableObject(&topMenu);


    PluginManager::addPlugins("/home/boris/CLionProjects/graphicEditor/Plugins", 
                              graphicEditor, toolBar);


    graphicEditor.run();
    PluginManager::closeAllPlugins();
    return 0;
}
