# Honeywell Zephyr I2C  [![Build Status](https://travis-ci.org/huilab/HoneywellZephyrI2C.svg?branch=master)](https://travis-ci.org/huilab/HoneywellZephyrI2C)
An Arduino library for communicating with Honeywell Zephyr HAF digital flow rate sensors over I2C.

Based on the Honeywell datasheets at https://sensing.honeywell.com/sensors/airflow-sensors/HAF-high-accuracy-50SCCM-750SCCM-series
#### View the documentation
https://huilab.github.io/HoneywellZephyrI2C/
#### Install
To download, click the Download Zip button. In the Arduino IDE go to Sketch -> Include Library -> Add .ZIP Library. 

Or, install this library with the Arduino Library Manager.

For details on installing libraries, see the guide at https://www.arduino.cc/en/Guide/Libraries#toc3
#### Use
Include the library and declare a sensor:
```C
#include <HoneywellZephyrI2C.h>
// construct a 50 SCCM sensor with address 0x49
ZephyrFlowRateSensor sensor( 0x49, 50 );
```
Initialize the sensor in `void setup()` :
```C
Wire.begin(); // start 2-wire communication
sensor.begin(); // run sensor initialization
```
Read values in `void loop()` :
```C
// the sensor returns 0 if new data is ready
if( sensor.readSensor() == 0 ) {
  float f = sensor.flow();
}
```
For more details, see the handy example sketch.
