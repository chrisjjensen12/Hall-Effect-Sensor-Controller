#include "include/Globals.h"
#include "include/HallEffect.h"

// "Sig" pin which is where the sensor's value will come in on
const int hallEffectSensorPin = 14; // A0

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  initHallEffect();

}

void loop() {

}



