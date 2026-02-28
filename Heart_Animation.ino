#include "LedControl.h"

/*
 * PIN CONNECTIONS:
 * VCC -> 5V
 * GND -> GND
 * DIN -> Pin 12
 * CS  -> Pin 10
 * CLK -> Pin 11
 */

// Initialize LedControl: DIN, CLK, CS, Number of Matrices (1)
LedControl lc = LedControl(12, 11, 10, 1);

// Big Heart Map
const byte bigHeart[8] = {
  B00000000,
  B01100110,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000
};

// Small Heart Map
const byte smallHeart[8] = {
  B00000000,
  B00000000,
  B00100100,
  B01011010,
  B00111100,
  B00011000,
  B00000000,
  B00000000
};

void setup() {
  // Wake up the MAX7219 from power-saving mode
  lc.shutdown(0, false);
  
  // Set brightness (0 is dim, 15 is max)
  lc.setIntensity(0, 4);
  
  // Clear the display
  lc.clearDisplay(0);
}

// Helper function to draw a frame on the matrix
void drawFrame(const byte frame[]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, frame[row]);
  }
}

void loop() {
  // 1. Show Big Heart
  drawFrame(bigHeart);
  delay(600); // Wait 0.6 seconds

  // 2. Show Small Heart
  drawFrame(smallHeart);
  delay(300); // Wait 0.3 seconds (faster pulse)
}
