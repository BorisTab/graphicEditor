#include "events.h"

ToolButtonClickEvent::ToolButtonClickEvent() {
    type = ToolButtonClicked;
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
