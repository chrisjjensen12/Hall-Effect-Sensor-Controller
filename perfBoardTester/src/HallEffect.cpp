#include "../include/HallEffect.h" 

// Mux enable pins
const int muxEnablePins[4] = {9, 8, 7, 6};

// Address pins
const int addressPins[4] = {10, 11, 12, 13};

// "Sig" pin which is where the sensor's value will come in on
const int hallEffectSensorPin = 14; // A0

void initHallEffect(void){

    // Set up address pins as outputs
    for(int i = 0; i < 4; i++){
        pinMode(addressPins[i], OUTPUT);
    }

    // Set up enable pins
    for(int i = 0; i < 4; i++){
        pinMode(muxEnablePins[i], OUTPUT);
    }

    // Set to high to disable multiplexers
    for(int i = 0; i < 4; i++){
        digitalWrite(muxEnablePins[i], HIGH);
    }

}

float readHallEffectSensor(uint8_t boardIndex){

    // Look up where we are
    MuxChannelMap HESensor = hallEffectLookupTable[boardIndex];
    uint8_t mux = HESensor.muxID;
    uint8_t channel = HESensor.channelID;

    // Enable mux for this sensor to read from it
    digitalWrite(muxEnablePins[mux], LOW); // low enables selected mux

    // Select channel within mux
    selectChannel(channel);

    // maybe add a small delay in here? (if it needs it)

    // Read from sensor
    float sensorValue = getSensorValue();

    // disable mux before leaving
    digitalWrite(muxEnablePins[mux], HIGH);

    return sensorValue;

}

void selectChannel(uint8_t channel) {
  // Set the control pins (S0-S3) based on the channel number
  digitalWrite(addressPins[0], (channel & 0x01) ? HIGH : LOW);
  digitalWrite(addressPins[1], (channel & 0x02) ? HIGH : LOW);
  digitalWrite(addressPins[2], (channel & 0x04) ? HIGH : LOW);
  digitalWrite(addressPins[3], (channel & 0x08) ? HIGH : LOW);
}

float getSensorValue(void){

  long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(hallEffectSensorPin);
  }
  int sensorValue = sum / 10;

  // Convert the averaged analog value to voltage (assuming 5V system)
  float voltage = sensorValue * (5.0 / 1023.0);

  return voltage;

}