/*
	Name:       eBike_firmware.ino
	Created:	25.03.2020 13:13:57
	Author:     Matej Suchanek      www.maker.matejsuchanek.cz      @makermatty

    Hello, this is a basic skeleton of the eBike ESP32 interaction control system.
    I will add and build more interactivity as I find free time.
    
    Documentations and schematics will follow.
*/

#include <Arduino.h>

#include "ebike.h"

#ifndef BAUDRATE
#define BAUDRATE 115200
#endif

ebike::Control eBike;

TimeTrack masterTime;

const int32_t blinkingCycle = 1000;
const int32_t rainbowCycle = 2000;

ebike::BlinkEffect blinkEffect(blinkingCycle, CRGB::Orange, CRGB::Black);
npe::RainbowEffect rainbowEffect(rainbowCycle);

void setup()
{
    Serial.begin(BAUDRATE);

    eBike.init();

    //////////////////////////////////////////////////////////////////  Web Ota Update Example  //////////////////////////////////////////////////////////////////////////

    if (eBike.Buttons.left.read() && eBike.Buttons.right.read()) {
        ebike::Update::start();
    }

    masterTime.setTime(0);
}

void loop()
{
    //////////////////////////////////////////////////////////////////  Buttons Example  //////////////////////////////////////////////////////////////////////////

    /* reading buttons */
    eBike.Buttons.update();

    if (eBike.Buttons.left.pressed()) {
        Serial.println("Left pressed!");
        delay(250);
    }

    if (eBike.Buttons.left.released()) {
        Serial.println("Left released!");
        delay(250);
    }

    if (eBike.Buttons.right.pressed()) {
        Serial.println("Right pressed!");
        delay(250);
    }

    if (eBike.Buttons.right.released()) {
        Serial.println("Right released!");
        delay(250);
    }

    //////////////////////////////////////////////////////////////////  Gyro + Acc Example  //////////////////////////////////////////////////////////////////////////

    int16_t gyro[3];
    int16_t acc[3];

    /* getting the gyro and acc data from the MPU6050 */
    eBike.Motion.getGyro(gyro);
    eBike.Motion.getAcc(acc);

    Serial.printf("%d, %d, %d, %d, %d, %d\n", gyro[0], gyro[1], gyro[2], acc[0], acc[1], acc[2]);

    //////////////////////////////////////////////////////////////////  Animation Example  //////////////////////////////////////////////////////////////////////////

    /* running time - generated animations on the bike */
    time_ms t = masterTime.time();

    /* running rainbow on the dashboard */
    rainbowEffect.at(t % rainbowEffect.duration(), &eBike.Neopixels.dashboard);

    /* solid red on the tail */
    fill_solid(eBike.Neopixels.tail.leds(), eBike.Neopixels.tail.length(), CRGB::Red);

    /* overlayed by blinking animation of the signal lights */
    blinkEffect.at(t % blinkEffect.duration(), &eBike.Neopixels.tailLeft);
    blinkEffect.at(t % blinkEffect.duration(), &eBike.Neopixels.tailRight);

    blinkEffect.at(t % blinkEffect.duration(), &eBike.Neopixels.signals);

    eBike.Neopixels.show();

    delay(10);
}
