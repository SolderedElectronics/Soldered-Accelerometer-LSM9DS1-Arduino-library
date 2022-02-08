/**
 **************************************************
 *
 * @file        SimpleGyroscope.ino
 * @brief       This example reads the gyroscope values from the LSM9DS1
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

  if (!LSM9.begin())  //Check if communication is started successfully
  {
    Serial.println("Failed to initialize LSM9!");
    while (1);
  }
  
  Serial.print("Gyroscope sample rate = ");
  Serial.print(LSM9.gyroscopeSampleRate()); //Get sample rate
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (LSM9.gyroscopeAvailable()) //Check if sensor has measured rotation rate
  {
    LSM9.readGyroscope(x, y, z);  //Get x, y and z axis rotation rate and
                                  //save them in variables

    Serial.print(x);              //Print x axis rotation rate
    Serial.print('\t');
    Serial.print(y);              //Print y axis rotation rate
    Serial.print('\t');
    Serial.println(z);            //Print z axis rotation rate
  }
}
