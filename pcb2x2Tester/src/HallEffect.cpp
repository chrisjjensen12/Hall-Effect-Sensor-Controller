#include "../include/HallEffect.h" 
#include "../include/Leds.h" 

// Mux enable pins E0, E1, E2, E3
const int muxEnablePins[4] = {9, 8, 7, 6};

// Address pins S0, S1, S2, S3
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

// reads the sensor state of the entire board 0-63
void readBoardState(void){

  for(int i = 0; i < NUM_TILES; i++){
    bool status = readHallEffectSensor(i);
    chessBoard[i].pieceDetected = status;
    toggleLed(i, status);
    delay(5);
  }

}

bool readHallEffectSensor(uint8_t boardIndex){

    bool pieceDetected = false;

    // Look up where we are
    TileInfo tile = TileLookupTable[boardIndex];
    uint8_t mux = tile.heSensorMuxID;
    uint8_t channel = tile.heSensorChannelID;

    // Enable mux for this sensor to read from it
    digitalWrite(muxEnablePins[mux], LOW); // low enables selected mux

    // Select channel within mux
    selectChannel(channel);

    // maybe add a small delay in here? (if it needs it)

    // Read from sensor
    float sensorValue = getSensorValue();

    // filter and determine from voltage if we're sensing a magnetic field from a piece
    if(sensorValue > 2.52){
      pieceDetected = true;
    }

    // Serial.print("Square ");
    // Serial.print(boardIndex);
    // Serial.print(": Voltage : ");
    // Serial.println(sensorValue);

    // disable mux before leaving
    digitalWrite(muxEnablePins[mux], HIGH);


    return pieceDetected;

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

  // Serial.print("Analog Value: ");
  // Serial.print(sensorValue);
  // Serial.print(" Voltage Value: ");
  // Serial.println(voltage);

  return voltage;

}
