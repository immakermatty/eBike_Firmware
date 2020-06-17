#ifdef ESP32

#include "ebikePeripherals.h"

namespace ebike {
PeripheralsClass::Peripheral::Peripheral(int pinNum, bool reverseLogic)
    : pin(pinNum)
    , logic(!reverseLogic)
{
    pinMode(pin, OUTPUT);
}

void PeripheralsClass::Peripheral::setOn()
{
    digitalWrite(pin, logic);
}

void PeripheralsClass::Peripheral::setOff()
{
    digitalWrite(pin, !logic);
}

PeripheralsClass::PeripheralsClass()
    : headlight(EBIKE_PIN_HEADLIGHT)
    , klaxon(EBIKE_PIN_KLAXON) {};

}

#endif