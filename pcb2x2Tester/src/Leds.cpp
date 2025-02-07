#include "../include/Leds.h" 

#define LED_DATA_PIN 4  // Pin connected to the data line of the WS2812B LED strip
#define NUM_LEDS 16  // Number of LEDs (one for each channel) (temporary, will be more later)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);

void initLeds(void){

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void toggleLed(uint8_t boardIndex, bool onOff){

    // Find led address from raw board index
    uint8_t ledAddress = TileLookupTable[boardIndex].ledAddress;

    if(onOff == true){
        strip.setPixelColor(ledAddress, strip.Color(255, 0, 0)); // Red
    }else{
        strip.setPixelColor(ledAddress, strip.Color(0, 0, 0)); // Off
    }

    strip.show();

}