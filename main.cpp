#include "../windowManager/application.h"
#include "consts.h"

int main() {
    Application graphicEditor(3840, 2160, "Graphic Editor");
    graphicEditor.setBackgroundColor(backgroundColor);
    graphicEditor.run();
    return 0;
}
