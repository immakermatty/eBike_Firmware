/** 
 * Author	: @makermatty (maker.matejsuchanek.cz)
 * Date		: 15-6-2020
 */

#ifdef ESP32

#ifndef _EBIKE_MOTION_h
#define _EBIKE_MOTION_h

#include <Arduino.h>
#include <MakerMatty_MPU6050_Motion.h>
#include "ebikeControl.h"

namespace ebike {

class MotionClass : Control {
public:
    MotionClass();
    // Disallow copying
    MotionClass(const MotionClass&) = delete;
    // Disallow assignment
    MotionClass& operator=(const MotionClass&) = delete;

    void begin();

    void getGyro(int16_t data[3]);
    void getAcc(int16_t data[3]);

private:
    MPU6050_Motion mpu6050_motion;
};

}
#endif
#endif