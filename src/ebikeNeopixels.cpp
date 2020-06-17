#ifdef ESP32

#include "ebikeNeopixels.h"

namespace ebike {

NeopixelsClass::NeopixelsClass()
    : tail(0)
    , signalRL(0)
    , signalRR(0)
    , signalFL(0)
    , signalFR(0)
    , dashboard(0)
    , signals(0)
    , all(0)
    , tailLeft(0)
    , tailRight(0)
{
    tail.setExternalBuffer(ledsBuffer.tailLeds, EBIKE_NEOPIXEL_LEDS_TAIL_COUNT);
    signalRL.setExternalBuffer(ledsBuffer.signalRlLeds, EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT);
    signalRR.setExternalBuffer(ledsBuffer.signalRrLeds, EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT);
    signalFL.setExternalBuffer(ledsBuffer.signalFlLeds, EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT);
    signalFR.setExternalBuffer(ledsBuffer.signalFrLeds, EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT);
    dashboard.setExternalBuffer(ledsBuffer.dashboardLeds, EBIKE_NEOPIXEL_LEDS_DASHBOARD_COUNT);

    signals.setExternalBuffer(ledsBuffer.signalRlLeds, 4 * EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT);
    all.setExternalBuffer(ledsBuffer.tailLeds, EBIKE_NEOPIXEL_LEDS_TAIL_COUNT + 4 * EBIKE_NEOPIXEL_LEDS_TURN_SIGNALS_COUNT + EBIKE_NEOPIXEL_LEDS_DASHBOARD_COUNT);

    tailLeft.setExternalBuffer(&ledsBuffer.tailLeds[0], 7);
    tailRight.setExternalBuffer(&ledsBuffer.tailLeds[EBIKE_NEOPIXEL_LEDS_TAIL_COUNT - 1] - 7, 7);
}

void NeopixelsClass::begin()
{
    /* big led strip rear turn signal, brake light, tail lights */
    FastLED.addLeds<EBIKE_NEOPIXEL_TYPE, EBIKE_PIN_NEOPIXEL_TAIL, EBIKE_NEOPIXEL_COLOR_ORDER>
        (tail.leds(), tail.length()).setCorrection(EBIKE_NEOPIXEL_COLOR_CORRECTION); 

    /* led strip rear left  turn signal */
    FastLED.addLeds<EBIKE_NEOPIXEL_TYPE, EBIKE_PIN_NEOPIXEL_SIGNALS_RL, EBIKE_NEOPIXEL_COLOR_ORDER>
        (signalRL.leds(), signalRL.length()).setCorrection(EBIKE_NEOPIXEL_COLOR_CORRECTION); 

    /* led strip rear right turn signal */
    FastLED.addLeds<EBIKE_NEOPIXEL_TYPE, EBIKE_PIN_NEOPIXEL_SIGNALS_RR, EBIKE_NEOPIXEL_COLOR_ORDER>
        (signalRR.leds(), signalRR.length()).setCorrection(EBIKE_NEOPIXEL_COLOR_CORRECTION); 

    /* led strip items left  turn signal */
    FastLED.addLeds<EBIKE_NEOPIXEL_TYPE, EBIKE_PIN_NEOPIXEL_SIGNALS_FL, EBIKE_NEOPIXEL_COLOR_ORDER>
        (signalFL.leds(), signalFL.length()).setCorrection(EBIKE_NEOPIXEL_COLOR_CORRECTION); 

    /* led strip items right turn signal */
    FastLED.addLeds<EBIKE_NEOPIXEL_TYPE, EBIKE_PIN_NEOPIXEL_SIGNALS_FR, EBIKE_NEOPIXEL_COLOR_ORDER>
        (signalFR.leds(), signalFR.length()).setCorrection(EBIKE_NEOPIXEL_COLOR_CORRECTION); 

    /* led strip dashboard */
    FastLED.addLeds<EBIKE_NEOPIXEL_TYPE, EBIKE_PIN_NEOPIXEL_DASHBOARD, EBIKE_NEOPIXEL_COLOR_ORDER>
        (dashboard.leds(), dashboard.length()).setCorrection(EBIKE_NEOPIXEL_COLOR_CORRECTION); 

    FastLED.setBrightness(EBIKE_NEOPIXEL_INITIAL_BRIGHTNESS);
}

void NeopixelsClass::show()
{
    FastLED.show();
}

void NeopixelsClass::brightness(const uint8_t value)
{
    FastLED.setBrightness(value);
}

const uint8_t NeopixelsClass::brightness() const
{
    return FastLED.getBrightness();
}

}

#endif