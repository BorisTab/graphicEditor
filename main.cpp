#include "../windowManager/application.h"
#include "consts.h"
#include "Canvas/canvas.h"

int main() {
    Application graphicEditor(windowWidth, windowHeight - 55, "Graphic Editor");
    graphicEditor.setBackgroundColor(backgroundColor);
    
    Canvas canvas(canvasStartX, canvasStartY, canvasHeight * canvasWidthCoeff, 
                  canvasHeight, Color(255, 255, 255), 
                  graphicEditor.getSystemEventManager());
    graphicEditor.addDrawableObject(&canvas);
    
    graphicEditor.run();
    return 0;
}
