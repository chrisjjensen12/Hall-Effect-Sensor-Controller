#include "include/Globals.h"
#include "include/HallEffect.h"
#include "include/Display.h"
#include "include/Leds.h"

void setup() {
  
  // Start the Serial Monitor
  Serial.begin(115200);
  initHallEffect();
  initLeds();

}

void loop() {

  readBoardState();

  // light up corresponding LED instead

  //printChessBoard();

  delay(1000);

}



