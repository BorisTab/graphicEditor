#ifndef EVENTS_GRAPHICEDITOR_H
#define EVENTS_GRAPHICEDITOR_H

#include "../../windowManager/application.h"

struct EditorEvent: public Event {
    enum EditorEventType {
        ToolButtonClicked = Event::UserEvent,
        ToolButtonChangeColor,
        ToolNumSend,
        ColorHueChanged,
        ColorSVChanged,
        SliderChangePosition,
        PointerChangePosition,
        SaveButtonClicked
    }; 
};

struct ToolButtonClickEvent: public EditorEvent {
    int pos = 0;

    ToolButtonClickEvent();
};

struct ToolButtonChangeColorEvent: public EditorEvent {
    ToolButtonChangeColorEvent();
};

struct ToolNumEvent: public EditorEvent {
    int toolNum = 0;

    ToolNumEvent();
};

struct ChangeHueColorEvent: public EditorEvent {
    int hue = 0;

    ChangeHueColorEvent();
};
struct ChangeSVColorEvent: public EditorEvent {
    int saturation = 0;
    int value = 0;

    ChangeSVColorEvent();
};

struct SliderChangePosEvent: public EditorEvent {
    int posX = 0;
    int posY = 0;

    SliderChangePosEvent();
};

struct PointerChangePosEvent: public EditorEvent {
    int posX = 0;
    int posY = 0;

    PointerChangePosEvent();
};

struct SaveButtonClickEvent: public EditorEvent {
    SaveButtonClickEvent();
};

#endif