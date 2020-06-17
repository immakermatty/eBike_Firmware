#ifdef ESP32

#include "ebikeButtons.h"

namespace ebike {

ButtonsClass::ButtonsClass()
    : left(EBIKE_PIN_BUTTON_SIGNAL_LEFT, BUTTON_DEBOUNCE_MS)
    , right(EBIKE_PIN_BUTTON_SIGNAL_RIGHT, BUTTON_DEBOUNCE_MS)
    , brake(EBIKE_PIN_BUTTON_BRAKE, BUTTON_DEBOUNCE_MS)
    , lights(EBIKE_PIN_BUTTON_LIGHTS, BUTTON_DEBOUNCE_MS)
    , klaxon(EBIKE_PIN_BUTTON_KLAXON, BUTTON_DEBOUNCE_MS)
{
}

void ButtonsClass::begin()
{
    uint32_t start = millis();

    while (millis() - start <= BUTTON_DEBOUNCE_MS * 2) {
        update();
        delay(1);
    }
}

void ButtonsClass::update()
{
    left.update();
    right.update();
    brake.update();
    lights.update();
    klaxon.update();
}
}
#endif