#include <Arduino.h>

// Address pins
#define S0 10
#define S1 11
#define S2 12
#define S3 13

// Mux enable pins
#define MUX1_EN 9
#define MUX2_EN 8
#define MUX3_EN 7
#define MUX4_EN 6

#define SIG_PIN 5  // Check this to get the value of the sensor when selected


void setup() {
  Serial.begin(115200);

  // Set up the control pins as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(MUX1_EN, OUTPUT);  // Enable pin, set it low to enable the multiplexer
  digitalWrite(MUX1_EN, LOW);
}

void loop() {
  // Iterate through all 16 channels of the multiplexer
  for (int channel = 0; channel < 16; channel++) {
    selectChannel(channel);
    delay(10);  // Allow time for the channel to settle
    
    // Read the sensor value
    int sensorValue = analogRead(SIG_PIN);
    
    // Print the channel and sensor value
    Serial.print("Channel ");
    Serial.print(channel);
    Serial.print(": ");
    Serial.println(sensorValue);
    delay(500);  // Delay between readings for readability
  }
}

void selectChannel(int channel) {
  // Set the control pins (S0-S3) based on the channel number
  digitalWrite(S0, (channel & 0x01) ? HIGH : LOW);
  digitalWrite(S1, (channel & 0x02) ? HIGH : LOW);
  digitalWrite(S2, (channel & 0x04) ? HIGH : LOW);
  digitalWrite(S3, (channel & 0x08) ? HIGH : LOW);
}
