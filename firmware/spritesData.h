#include <Arduino.h>

const uint16_t epd_bitmap_KikoSpriteIdle1Cropped[];
const uint16_t epd_bitmap_KikoSpriteLeft1Cropped[];
const uint16_t epd_bitmap_KikoSpriteRight2Cropped[];
const uint16_t epd_bitmap_KikoSpriteIdle2Cropped[];
const uint16_t epd_bitmap_KikoSpriteRight1Cropped[];
const uint16_t epd_bitmap_KikoSpriteLeft2Cropped[]];

// array of all bitmaps (Total bytes used to store images in PROGMEM = 7872)
const int epd_bitmap_allArray_LEN = 6;
const uint16_t* epd_bitmap_allArray[6];

int spriteW = 32;
int spriteH = 32;
