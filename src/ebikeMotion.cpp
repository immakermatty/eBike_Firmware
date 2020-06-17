#ifdef ESP32

#include "ebikeMotion.h"

namespace ebike {

MotionClass::MotionClass()
    : mpu6050_motion()
{
}

void MotionClass::begin()
{
    mpu6050_motion.begin(EBIKE_PIN_GYRO_SDA, EBIKE_PIN_GYRO_SCL, 400000U, APP_CPU_NUM);
}

void MotionClass::getGyro(int16_t data[3])
{
    mpu6050_motion.getGyro(data);
}

void MotionClass::getAcc(int16_t data[3])
{
    mpu6050_motion.getAcc(data);
}

}
#endif
