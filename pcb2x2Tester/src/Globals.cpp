#include "../include/Globals.h" 


TileInfo TileLookupTable[NUM_TILES] = {
  {0, 0, 0}, {0, 1, 1}, {0, 2, 2}, {0, 3, 3},
  {1, 0, 4}, {1, 1, 5}, {1, 2, 6}, {1, 3, 7},
  {2, 0, 8}, {2, 1, 9}, {2, 2, 10}, {2, 3, 11},
  {3, 0, 12}, {3, 1, 13}, {3, 2, 14}, {3, 3, 15},
};

TileState chessBoard[NUM_TILES];