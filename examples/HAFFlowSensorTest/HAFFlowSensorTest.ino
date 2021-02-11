/*
 * FlowRateSensorTest
 *
 * Fetch and print values from a Honeywell
 * Zephyr HAF Pressure Sensor over I2C
 *
 * The sensor values used in this demo are
 * for a 50 SCCM sensor with address 0x49
 * (PN: HAF BLF 0050 C4AX5)
 *
 */

#include <HoneywellZephyrI2C.h>

// construct a 50 SCCM sensor with address 0x49
ZephyrFlowRateSensor sensor(0x49, 50, ZephyrFlowRateSensor::SCCM);

void setup() {
  Serial.begin(115200); // start Serial communication
  Wire.begin(); // start 2-wire communication
  Wire.setClock(400000L); // this sensor supports fast-mode
  sensor.begin(); // run sensor initialization
}

void loop() {
  // the sensor returns 0 when new data is ready
  if( sensor.readSensor() == 0 ){
    Serial.print( "Flow rate: " );
    Serial.print( sensor.flow() );
    Serial.println( " [SCCM]" );
  }

  delay( 100 ); // Slow down sampling to 10 Hz. This is just a test.

}
