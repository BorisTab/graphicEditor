#include "events.h"

ToolButtonClickEvent::ToolButtonClickEvent() {
    type = ToolButtonClicked;
}

ToolButtonChangeColorEvent::ToolButtonChangeColorEvent() {
    type = ToolButtonChangeColor;
}

ToolNumEvent::ToolNumEvent() {
    type = ToolNumSend;
}

ChangeHueColorEvent::ChangeHueColorEvent() {
    type = ColorHueChanged;
}

ChangeSVColorEvent::ChangeSVColorEvent() {
    type = ColorSVChanged;
}

SliderChangePosEvent::SliderChangePosEvent() {
    type = SliderChangePosition;
}

PointerChangePosEvent::PointerChangePosEvent() {
    type = PointerChangePosition;
}

SaveButtonClickEvent::SaveButtonClickEvent() {
    type = SaveButtonClicked;
}
