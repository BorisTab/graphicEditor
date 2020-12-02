#ifndef EVENTS_GRAPHICEDITOR_H
#define EVENTS_GRAPHICEDITOR_H

#include "../../windowManager/application.h"

struct EditorEvent: public Event {
    enum EditorEventType {
        ToolButtonClicked = Event::UserEvent,
        ToolNumSend,
        ColorHueChanged,
        ColorSVChanged
    }; 
};

struct ToolButtonClickEvent: public EditorEvent {
    int pos = 0;

    ToolButtonClickEvent();
};

struct ToolNumEvent: public EditorEvent {
    int toolNum = 0;

    ToolNumEvent();
};

struct ChangeHueColorEvent: EditorEvent {
    int hue = 0;

    ChangeHueColorEvent();
};
struct ChangeSVColorEvent: EditorEvent {
    int saturation = 0;
    int value = 0;

    ChangeSVColorEvent();
};

#endif