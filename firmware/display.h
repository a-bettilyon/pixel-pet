#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h> 

#include "petState.h"

#define TFT_CS 9
#define TFT_RST 7
#define TFT_DC 8
#define TFT_BS 5


Adafruit_ST7789 tft(TFT_CS, TFT_DC, TFT_RST);
//Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST, SPI_MOSI, SPI_SCK, TFT_CS);

// const int TFT_CS = 9;
// const int TFT_RST = 7;
// const int TFT_DC = 8;
// const int TFT_BS = 5;

enum spriteDirection {
  dirIdle
  dirLeft
  dirRight
};

const uint16_t  BLACK   = 0x0000;
const uint16_t  BLUE    = 0x001F;
const uint16_t  RED     = 0xF800;
const uint16_t  GREEN   = 0x07E0;
const uint16_t  CYAN    = 0x07FF;
const uint16_t  MAGENTA = 0xF81F;
const uint16_t  YELLOW  = 0xFFE0;
const uint16_t  WHITE   = 0xFFFF;

void initSprite();
void updateSprite();

