#include "include/Globals.h"
#include "include/HallEffect.h"
#include "include/Display.h"

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);
  initHallEffect();

}

void loop() {

  readBoardState();

  printChessBoard();

  delay(1000);

}



