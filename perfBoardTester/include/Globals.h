#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#define NUM_HALL_EFFECT_SENSORS 64

/////////////////////////////////////////////////// Structures

typedef struct {
    uint8_t muxID;
    uint8_t channelID;
} MuxChannelMap;

typedef struct {
    bool pieceDetected;
} Tile;

/////////////////////////////////////////////////// Variables

// Lookup table for sensor # to mux/channel
extern MuxChannelMap hallEffectLookupTable[64];

// Board made of tiles
extern Tile chessBoard[64];


#endif // GLOBALS_H
