#ifndef HALLEFFECT_H
#define HALLEFFECT_H
#include "Globals.h"  

void initHallEffect(void);
void readBoardState(void);
bool readHallEffectSensor(uint8_t boardIndex);
void selectChannel(uint8_t channel);
float getSensorValue(void);
void readBoard(uint8_t boardNum);

#endif // HALLEFFECT_H