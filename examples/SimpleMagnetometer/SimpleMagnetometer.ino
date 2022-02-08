/**
 **************************************************
 *
 * @file        SimpleGyroscope.ino
 * @brief       This example reads the magnetic field values from the LSM9DS1
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
  
  Serial.print("Magnetic field sample rate = ");
  Serial.print(LSM9.magneticFieldSampleRate()); //Get sample rate
  Serial.println(" uT");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");
}

void loop() {
  float x, y, z;

  if (LSM9.magneticFieldAvailable()) //Check if sensor has measured magnetic fields
  {
    LSM9.readMagneticField(x, y, z);  //Get x, y and z axis magnetic field and
                                      //save them in variables

    Serial.print(x);                  //Print x axis magnetic field
    Serial.print('\t');               
    Serial.print(y);                  //Print y axis magnetic field
    Serial.print('\t');
    Serial.println(z);                //Print z axis magnetic field
  } 
}
