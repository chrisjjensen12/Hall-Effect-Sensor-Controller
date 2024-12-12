#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

#define NUM_HALL_EFFECT_SENSORS 64

/////////////////////////////////////////////////// Structures

typedef struct {
    uint8_t heSensorMuxID; // Hall effect sensor mux ID
    uint8_t heSensorChannelID; // Hall effect sensor channel for mux
    uint8_t ledAddress; // LED address 
} TileInfo;

typedef struct {
    bool pieceDetected;
} TileState;

/////////////////////////////////////////////////// Variables

// Lookup table for sensor # to mux/channel
extern TileInfo TileLookupTable[64];

// Board made of tiles
extern TileState chessBoard[64];


#endif // GLOBALS_H
