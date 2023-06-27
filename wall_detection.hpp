#include <Wire.h>
#include <VL6180X.h>

#include "lidar_setup.hpp"




#pragma once

#include <Arduino.h>
#include "MovingAverageFilter.hpp"
#include "UltrasonicSensor.hpp"

template <size_t N>
class wall_detection : public UltrasonicSensor {
public: 
    // COMPLETE THIS CONSTRUCTOR.
    wall_detection(UltrasonicSensor& sensor) : UltrasonicSensor(sensor) {
    }


    void sensorSetup() {
      lidarSetup();
      Serial.println("Set up Succses");
      
    }


    void checkWalls() {
        // ultrasonic
        //adds to buffer, outputs to monitor, updates variable
        filter.sample(echo());
        frontReading = filter.average();
        Serial.print("\tDistanceF: ");
        Serial.print(frontReading = filter.average(););
      
        // print out readings lidar
        Serial.print("\tDistanceL: ");
        leftReading = sensorL.readRangeContinuousMillimeters();
        Serial.print(sensorL.readRangeContinuousMillimeters());
        if (sensorL.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
        Serial.print("\tDistanceR: ");
        rightReading = sensorR.readRangeContinuousMillimeters();
        Serial.print(sensorR.readRangeContinuousMillimeters());
        if (sensorR.timeoutOccurred()) { Serial.print(" TIMEOUT"); }
        
        Serial.println();

        
        //change left side 
        if (sensorL.readRangeContinuousMillimeters() < 100) {
          wallL = true;
        } else {
          wallL = false;
        }
        //change right side
        if (sensorR.readRangeContinuousMillimeters() < 100) {
          wallR = true;
        } else {
          wallR = false;
        }
    
    }

    float rightDistance() {
      return rightReading;
    }

    float leftDistance() {
      return leftReading;
    }

    float frontDistance() {
      return frontReading;
    }

private:
    MovingAverageFilter<float, N> filter;
    float leftReading = 0;
    float rightReading = 0;
    float frontReading = 0;
    bool wallL = false
    bool wallR = false
    bool wallF = false
};
