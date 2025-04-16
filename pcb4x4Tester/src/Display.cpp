#include "../include/Display.h" 

void printChessBoard() {
    const int BOARD_SIZE = 8; // Chessboard is 8x8
    const int GRID_SIZE = 4;  // Separate every 4x4 grid

    for (int row = 0; row < BOARD_SIZE; row++) {
        // Print top boundary of each row
        for (int col = 0; col < BOARD_SIZE; col++) {
            Serial.print("+---");
            if ((col + 1) % GRID_SIZE == 0 && col != BOARD_SIZE - 1) {
                Serial.print("+   "); // Two spaces for horizontal separation
            }
        }
        Serial.println("+");

        // Print middle row with content
        for (int col = 0; col < BOARD_SIZE; col++) {
            // Calculate index for bottom-right numbering
            int index = (BOARD_SIZE - 1 - row) * BOARD_SIZE + (BOARD_SIZE - 1 - col);
            Serial.print("| ");
            Serial.print(chessBoard[index].pieceDetected ? 'x' : ' ');
            Serial.print(" ");
            if ((col + 1) % GRID_SIZE == 0 && col != BOARD_SIZE - 1) {
                Serial.print("|   "); // Two spaces for horizontal separation
            }
        }
        Serial.println("|");

        // After every 4th row, add vertical spacing
        if ((row + 1) % GRID_SIZE == 0 && row != BOARD_SIZE - 1) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                Serial.print("+---");
                if ((col + 1) % GRID_SIZE == 0 && col != BOARD_SIZE - 1) {
                    Serial.print("+   "); // Two spaces for horizontal separation
                }
            }
            Serial.println("+");
            Serial.println(); // Extra blank line for vertical separation
        }
    }

    // Print bottom boundary of the board
    for (int col = 0; col < BOARD_SIZE; col++) {
        Serial.print("+---");
        if ((col + 1) % GRID_SIZE == 0 && col != BOARD_SIZE - 1) {
            Serial.print("+   "); // Two spaces for horizontal separation
        }
    }
    Serial.println("+");
}
