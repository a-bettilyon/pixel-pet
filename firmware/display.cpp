#include "display.h"
#include "spritesData.h"
#include "display.h"

int pixelScale = 4;
unsigned long animationInterval = 600;
int currentFrame = 0;
unsigned long lastFrame = 0;

void initSprite() {
  lastFrame = millis();
}

void pixelateSprite(const uint16_t *bitmap, int x, int y, int w, int h, int scale) {
  for (int row = 0; row < h; row++) {
    for (int col = 0; col < w; col++) {
      uint32_t color = pgm_read_dword(&bitmap[row * w + col]);
      if (color != 0) { //skip transparent pixels
        tft.fillRect(x + col * scale, y + row * scale, scale, scale, color);
      }
    }
  }
}

void updateSprite() {
  unsigned long now = millis();
  if(now - lastFrame >= animationInterval) {
    currentFrame = 1 - currentFrame;
    lastFrame = now;
  }

}