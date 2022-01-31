/**
 **************************************************
 *
 * @file        SimpleAccelerometer.ino
 * @brief       This example reads the acceleration values from the LSM9DS1
 *              sensor and continuously prints them to the Serial Monitor
 *              or Serial Plotter.
 *
 *  product: www.solde.red/333069
 *
 * @authors     Riccardo Rizzo
 * 
 * Modified by Soldered.com
 ***************************************************/

#include <LSM9DS1-Accelerometer-library-SOLDERED.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!LSM9.begin()) 
  {
    Serial.println("Failed to initialize LSM9!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(LSM9.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (LSM9.accelerationAvailable()) 
  {
    LSM9.readAcceleration(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);
  }
}
