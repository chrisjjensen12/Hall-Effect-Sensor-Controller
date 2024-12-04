#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

/////////////////////////////////////////////////// Structures

typedef struct {
    uint8_t muxID;
    uint8_t channelID;
} MuxChannelMap;

/////////////////////////////////////////////////// Variables

extern MuxChannelMap hallEffectLookupTable[64];


#endif // GLOBALS_H
