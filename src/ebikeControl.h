/** 
 * Author	: @makermatty (maker.matejsuchanek.cz)
 * Date		: 15-6-2020
 */

#ifdef ESP32

#ifndef _EBIKE_CONTROL_h
#define _EBIKE_CONTROL_h

#include <Arduino.h>

#include "ebikeConfig.h"

namespace ebike {

class ButtonsClass;
class PeripheralsClass;
class MotionClass;
class NeopixelsClass;

class Control {
public:
    // Allow instances
    Control();
    // Disallow copying
    Control(const Control&) = delete;
    // Disallow assignment
    Control& operator=(const Control&) = delete;

    void init();

    static ebike::NeopixelsClass &Neopixels;
    static ebike::ButtonsClass& Buttons;
    static ebike::PeripheralsClass& Peripherals;
    static ebike::MotionClass& Motion;
};
}

#endif
#endif