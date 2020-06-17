/** 
 * Author	: @makermatty (maker.matejsuchanek.cz)
 * Date		: 15-6-2020
 */

#ifdef ESP32

#ifndef _EBIKE_NEOPIXELS_h
#define _EBIKE_NEOPIXELS_h

#include "ebikeControl.h"
#include <Arduino.h>
#include <MakerMatty_NeoAni.h>

namespace ebike {

struct /* __attribute__((packed)) */ EbikeLeds {
    CRGB tailLeds[EBIKE_NEOPIXEL_LEDS_TAIL_COUNT];
    CRGB signalRlLeds[EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT];
    CRGB signalRrLeds[EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT];
    CRGB signalFlLeds[EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT];
    CRGB signalFrLeds[EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT];
    CRGB dashboardLeds[EBIKE_NEOPIXEL_LEDS_DASHBOARD_COUNT];
};

class NeopixelsClass : Control {
public:
    NeopixelsClass();
    // Disallow copying
    NeopixelsClass(const NeopixelsClass&) = delete;
    // Disallow assignment
    NeopixelsClass& operator=(const NeopixelsClass&) = delete;

    void begin();
    void show();

    inline void brightness(const uint8_t value);
    inline const uint8_t brightness() const;

private:
    EbikeLeds ledsBuffer;

public:
    npa::Neopixels tail;
    npa::Neopixels signalRL;
    npa::Neopixels signalRR;
    npa::Neopixels signalFL;
    npa::Neopixels signalFR;
    npa::Neopixels dashboard;

    npa::Neopixels signals;
    npa::Neopixels all;

    npa::Neopixels tailLeft;
    npa::Neopixels tailRight;
};
}

#endif
#endif