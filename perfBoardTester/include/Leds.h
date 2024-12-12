#ifndef LEDS_H
#define LEDS_H
#include "Globals.h"  
#include <Adafruit_NeoPixel.h>

void initLeds(void);
void toggleLed(uint8_t boardIndex, bool onOff);

#endif // LEDS_H