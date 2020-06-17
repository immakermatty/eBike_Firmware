/** 
 * Author	: @makermatty (maker.matejsuchanek.cz)
 * Date		: 15-6-2020
 */

#ifdef ESP32

#ifndef _EBIKE_EFFECTS_h
#define _EBIKE_EFFECTS_h

#define FASTLED_INTERNAL
#include <FastLED.h>
#include "MakerMatty_NeoAni.h"

namespace ebike {

//////////////////////////////////////////////////////////////////////////////////////////////

class TurnSignalEffect : public npa::Effect {
    void onAt(const time_ms time, const time_ms duration, npa::Frame* const frame) override
    {
        // TO-DO
    }

public:
    TurnSignalEffect(time_ms duration, CRGB color)
        : Effect(duration)
        , color(color) {};

private:
    CRGB color;
};

//////////////////////////////////////////////////////////////////////////////////////////////

class BlinkEffect : public npa::Effect {
    void onAt(const time_ms time, const time_ms duration, npa::Frame* const frame) override
    {
        bool state = (time * 2) / duration;

        if (state) {
            fill_solid(frame->leds(), frame->length(), color1);
        } else {
            fill_solid(frame->leds(), frame->length(), color2);
        }
    }

public:
    BlinkEffect(time_ms duration, CRGB color1, CRGB color2)
        : Effect(duration)
        , color1(color1)
        , color2(color2) {};

private:
    CRGB color1;
    CRGB color2;
};

//////////////////////////////////////////////////////////////////////////////////////////////
}

#endif
#endif