/**
 **************************************************
 *
 * @file        LSM9DS1-Accelerometer-library-SOLDERED.h
 * @brief       Soldered LS9DS1 Arduino Library.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com, Robert Peric
 ***************************************************/

#ifndef _LSM9DS1_H
#define _LSM9DS1_H

#include "Arduino.h"
#include "libs/Arduino_LSM9DS1/src/LSM9DS1.h"

class LSM9DS1 : public LSM9DS1Class
{
  public:
    LSM9DS1(TwoWire &wire);

  protected:
  private:
};

extern LSM9DS1 LSM9;

#endif
