#include <Wire.h>
#include <VL6180X.h>

#define RANGE 1

/* List of adresses for each sensor - after reset the address can be configured */
#define addressL 0x20
#define addressR 0x22
// #define address2 0x24
// #define address1 0x26
// #define address1 0x28
// #define address1 0x30
// #define address1 0x32

/* These Arduino pins must be wired to the IO0 pin of VL6180x */
int enablePinR = 34;
int enablePinL = 35;
//int enablePin2 = 9;
//int enablePin3 = 8;
//int enablePin4 = 7;
//int enablePin5 = 6;
//int enablePin6 = 5;

/* Create a new instance for each sensor */
VL6180X sensorL;
VL6180X sensorR;
//VL6180X sensor2;
//VL6180X sensor3;
//VL6180X sensor4;
//VL6180X sensor5;
//VL6180X sensor6;

void lidarSetup()
{
  Serial.begin(9600);
  Wire.begin();

  // Reset all connected sensors
  pinMode(enablePinL,OUTPUT);
  pinMode(enablePinR,OUTPUT);
  //pinMode(enablePin2,OUTPUT);
  //pinMode(enablePin3,OUTPUT);
  //pinMode(enablePin4,OUTPUT);
  //pinMode(enablePin5,OUTPUT);
  //pinMode(enablePin6,OUTPUT);
  
  digitalWrite(enablePinL, LOW);
  digitalWrite(enablePinR, LOW);
  //digitalWrite(enablePin2, LOW);
  //digitalWrite(enablePin3, LOW);
  //digitalWrite(enablePin4, LOW);
  //digitalWrite(enablePin5, LOW);
  //digitalWrite(enablePin6, LOW);
  
  delay(1000);
  
  // sensorL
  Serial.println("Start Sensor Left");
  digitalWrite(enablePinL, HIGH);
  delay(50);
  sensorL.init();
  sensorL.configureDefault();
  sensorL.setAddress(addressL);
  Serial.println(sensorL.readReg(0x212),HEX); // read I2C address
  sensorL.writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
  sensorL.writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);
  sensorL.setTimeout(500);
  sensorL.stopContinuous();
  sensorL.setScaling(RANGE); // configure range or precision 1, 2 oder 3 mm
  delay(300);
  sensorL.startInterleavedContinuous(100);
  delay(100);
  
  // sensorR
  Serial.println("Start Sensor Right");
  digitalWrite(enablePinR, HIGH);
  delay(50);
  sensorR.init();
  sensorR.configureDefault();
  sensorR.setAddress(addressR);
  Serial.println(sensorR.readReg(0x212),HEX);
  sensorR.writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
  sensorR.writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);
  sensorR.setTimeout(500);
  sensorR.stopContinuous();
  sensorR.setScaling(RANGE);
  delay(300);
  sensorR.startInterleavedContinuous(100);
  delay(100);

//  Sensor2
//  Serial.println("Start Sensor 2");
//  digitalWrite(enablePin2, HIGH);
//  delay(50);
//  sensor2.init();
//  sensor2.configureDefault();
//  sensor2.setAddress(address2);
//  Serial.println(sensor2.readReg(0x212),HEX);
//  sensor2.writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
//  sensor2.writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);
//  sensor2.setTimeout(500);
//  sensor2.stopContinuous();
//  sensor2.setScaling(RANGE);
//  delay(300);
//  sensor2.startInterleavedContinuous(100);
  
  // copy & paste as much sensors as you require
  
  delay(1000);
 
  Serial.println("Sensors ready! Start reading sensors in 3 seconds ...!");
  delay(3000);


}
