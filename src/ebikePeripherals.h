/** 
 * Author	: @makermatty (maker.matejsuchanek.cz)
 * Date		: 15-6-2020
 */

#ifdef ESP32

#ifndef _EBIKE_PERIPHERALS_h
#define _EBIKE_PERIPHERALS_h

#include "ebikeControl.h"
#include <Arduino.h>

namespace ebike {

class PeripheralsClass : Control {

    class Peripheral {
    public:
        Peripheral(int pinNum, bool reverseLogic = false);

        void setOn();
        void setOff();

    private:
        int pin;
        bool logic;
    };

public:
    PeripheralsClass();
    // Disallow copying
    PeripheralsClass(const PeripheralsClass&) = delete;
    // Disallow assignment
    PeripheralsClass& operator=(const PeripheralsClass&) = delete;

    void begin() {};

    Peripheral headlight;
    Peripheral klaxon;

private:
};
}

#endif
#endif
