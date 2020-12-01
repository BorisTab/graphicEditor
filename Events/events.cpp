#include "events.h"

ToolButtonClickEvent::ToolButtonClickEvent() {
    type = ToolButtonClicked;
}

ToolNumEvent::ToolNumEvent() {
    type = ToolNumSend;
}