#ifndef EVENTS_GRAPHICEDITOR_H
#define EVENTS_GRAPHICEDITOR_H

#include "../../windowManager/application.h"

struct EditorEvent: public Event {
    enum EditorEventType {
        ToolButtonClicked = Event::UserEvent,
        ToolNumSend
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

#endif