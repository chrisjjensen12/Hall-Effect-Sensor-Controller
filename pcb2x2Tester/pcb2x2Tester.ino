#include "include/Globals.h"
#include "include/HallEffect.h"
#include "include/Display.h"
#include "include/Leds.h"

void setup() {
  
  // Start the Serial Monitor
  Serial.begin(115200);
  initHallEffect();
  initLeds();

  // toggleLed(0, true);
  // toggleLed(1, true);
  // toggleLed(2, true);
  // toggleLed(3, true);

}

void loop() {

  readBoardState();

  // light up corresponding LED instead

  //printChessBoard();

}



