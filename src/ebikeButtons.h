// ebike_peripherals.h

#ifndef _EBIKE_BUTTONS_h
#define _EBIKE_BUTTONS_h

#include <Arduino.h>
#include <MakerMatty_Button.h>

#include "ebikeControl.h"

#define BUTTON_DEBOUNCE_MS 10

namespace ebike {

class ButtonsClass : Control {
public:
    ButtonsClass();
    // Disallow copying
    ButtonsClass(const ButtonsClass&) = delete;
    // Disallow assignment
    ButtonsClass& operator=(const ButtonsClass&) = delete;

    void begin();

    void update();

    Button left;
    Button right;
    Button brake;
    Button lights;
    Button klaxon;
};
}

#endif