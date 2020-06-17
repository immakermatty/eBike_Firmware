#ifdef ESP32

#include "ebikeControl.h"

#include "ebikeButtons.h"
#include "ebikeMotion.h"
#include "ebikePeripherals.h"
#include "ebikeNeopixels.h"

namespace ebike {

ebike::NeopixelsClass& ebike::Control::Neopixels(*(new ebike::NeopixelsClass()));
ebike::ButtonsClass& ebike::Control::Buttons(*(new ebike::ButtonsClass()));
ebike::PeripheralsClass& ebike::Control::Peripherals(*(new ebike::PeripheralsClass()));
ebike::MotionClass& ebike::Control::Motion(*(new ebike::MotionClass()));

Control::Control()
{
}

void Control::init()
{
    Buttons.begin();
    Peripherals.begin();
    Motion.begin();
    Neopixels.begin();
}

}

#endif