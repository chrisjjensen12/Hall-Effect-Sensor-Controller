#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

////////////////////////////////////////////////////////////////////////////////////////// Defines

////////////////// Hall Effect Sensors

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
#define SENSOR_THRESHOLD 500 // Threshold for determining if the sensor value is high

////////////////// LEDs

#define LED_DATA_PIN 4  // Pin connected to the data line of the WS2812B LED strip
#define NUM_LEDS 16  // Number of LEDs (one for each channel) (temporary, will be more later)

////////////////////////////////////////////////////////////////////////////////////////// Globals

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);

////////////////////////////////////////////////////////////////////////////////////////// Local Functions

void selectChannel(int channel);
void updateLed(int ledIndex, int HESensorValue);

////////////////////////////////////////////////////////////////////////////////////////// Main Loop

void setup() {
  Serial.begin(115200);

  // Initialize the LED strip
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

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

    updateLed(channel, sensorValue);

    delay(500);  // Delay between readings for readability
  }
}

////////////////////////////////////////////////////////////////////////////////////////// Helper Functions

void updateLed(int ledIndex, int HESensorValue){
  // Check if the sensor value is high and update the corresponding LED
  if (HESensorValue > SENSOR_THRESHOLD) {
    strip.setPixelColor(ledIndex, strip.Color(255, 0, 0)); // Red
  } else {
    strip.setPixelColor(ledIndex, strip.Color(0, 0, 0)); // Off
  }
  strip.show(); // Update the LED strip with the new colors
}

void selectChannel(int channel) {
  // Set the control pins (S0-S3) based on the channel number
  digitalWrite(S0, (channel & 0x01) ? HIGH : LOW);
  digitalWrite(S1, (channel & 0x02) ? HIGH : LOW);
  digitalWrite(S2, (channel & 0x04) ? HIGH : LOW);
  digitalWrite(S3, (channel & 0x08) ? HIGH : LOW);
}
