#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define HE0 A0
#define HE1 A1

#define LED_DATA_PIN 4  // Pin connected to the data line of the WS2812B LED strip
#define NUM_LEDS 2  // Number of LEDs (one for each channel) (temporary, will be more later)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(115200);

  // Initialize the LED strip
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'


}

void loop() {

  float voltage = (analogRead(HE0) / 1023.0) * 5.0;
  Serial.print("Voltage: ");
  Serial.println(voltage, 3);

  if(voltage >= 2.60){
    strip.setPixelColor(1, strip.Color(255, 0, 0)); // Red
  }else{
    strip.setPixelColor(1, strip.Color(0, 0, 0)); // Off
  }

  strip.show();

  delay(500);

}
