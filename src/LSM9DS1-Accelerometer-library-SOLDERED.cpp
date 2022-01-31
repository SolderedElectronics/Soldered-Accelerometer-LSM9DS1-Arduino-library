/**
 **************************************************
 *
 * @file        LSM9DS1-Accelerometer-library-SOLDERED.cpp
 * @brief       Soldered LSM9DS1 Arduino Library.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/


#include "LSM9DS1-Accelerometer-library-SOLDERED.h"

/**
 * @brief                   Constructor.
 *
 */
LSM9DS1::LSM9DS1(TwoWire &wire) : LSM9DS1Class(wire)
{
}

#ifdef ARDUINO_ARDUINO_NANO33BLE
LSM9DS1 LSM9(Wire1);
#else
LSM9DS1 LSM9(Wire);
#endif