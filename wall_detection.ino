
#include <Arduino.h>

#include <Wire.h>
#include <VL6180X.h>

#include "wall_detection.hpp"

#include "UltrasonicSensor.hpp"


void setup() {
  Serial.begin(115200);
  %set up wall detection class
  mtrn3100::UltrasonicSensor sensor(40, A13);
  wall_detection<100> detector(sensor)

  detector.sensorSetup();

  detector.checkwalls

}

void loop() {
  // put your main code here, to run repeatedly:

}
