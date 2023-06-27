#pragma once

#include <Arduino.h>

namespace mtrn3100 {

class UltrasonicSensor {
public:
    // COMPLETE THIS CONSTRUCTOR.
    UltrasonicSensor(uint8_t trigger_pin, uint8_t echo_pin): trigger_pin(trigger_pin), echo_pin(echo_pin)  {
        pinMode(trigger_pin, OUTPUT), 
        pinMode(echo_pin, INPUT); 
        //distance = 0, 
        //duration = 0;
      }

    // COMPLETE THIS FUNCTION.
    float echo() const { 
          digitalWrite(trigger_pin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigger_pin, LOW);
          float duration = pulseIn(echo_pin, HIGH);
          
          //distance in mm
          float distance =  duration * 0.1715;
          
          return distance + 11;
      }

private:
    const uint8_t trigger_pin;
    const uint8_t echo_pin;
    //float distance;
    //float duration;
};

}  // namespace mtrn3100
