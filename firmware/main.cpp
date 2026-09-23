// #include <Arduino_DataBus.h>
// #include <Arduino_G.h>
// #include <Arduino_GFX.h>
// #include <Arduino_GFX_Library.h>
// #include <Arduino_OLED.h>
// #include <Arduino_TFT.h>
// #include <Arduino_TFT_18bit.h>
// #include <YCbCr2RGB.h>
// #include <gfxfont.h>

// #include <Adafruit_ST7735.h>
// #include <Adafruit_ST7789.h>
// #include <Adafruit_ST7796S.h>
// #include <Adafruit_ST77xx.h>

/* Pixel Pet ESP32 Code */

/* Peripherals List

1. 2171790001 USB-C Receptacle: Differential Pair
    D+ on pin 14
    D- on pin 13

2. BMI323 Gyrometer/Accelerometer: SPI
    MOSI on pin 19 (IO11)
    MISO on pin 21 (IO13)
    SCK on pin 20 (IO12)
    CS on pin 18 (IO10)
    
3. ST7789 TFT Display: SPI
    MOSI on pin 19 (IO11)
    no MISO
    SCK on pin 20 (IO12)
    CS on pin 17 (IO9)
    RST on pin 7 (IO7)
    DC on pin 12 (IO8)
    BS on pin 5 (IO5)

4. LDR: ADC
    ADC on pin 4 (IO4)

5. Buttons
    BTN A on pin 22 (IO14)
    BTN_B on pin 38 (IO2)
    BTN_C on pin 39 (IO1)
    BOOT on pin 27 (IO0) - active LOW
    RESET on pin 3 (EN) - active LOW

6. Buzzer
    BUZZER_PWM on pin 31 (IO38)

*/

#include <Arduino.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#include "main.h"
#include "petState.h"
#include "buttons.h"
#include "display.h"


petState pixelPet;

void setup() {
    Serial.begin(9600);

    pinMode(BTN_A_PIN, INPUT_PULLUP);
    pinMode(BTN_B_PIN, INPUT_PULLUP);
    pinMode(BTN_C_PIN, INPUT_PULLUP);
    
    //IMU init
    if(imu.beginSPI(IMU_CS)) {
        Serial.println("Calibrating IMU...");
        delay(calibDelayIMU);
        imu.calibrateGyro(1, true);
        Serial.print("Done");
    } else Serial.println("IMU init failed!");

    //TFT init
    tft.init(240, 240);
    tft.setRotation(0);
    tft.fillScreen(0x00000);
    tft.print("Look at us. We just keep saying goodbye, don't we? But this isn't an end. It's a chance to make amends, to rectify mistakes. And it starts here: I was wrong.");
    delay(1000);

}

void loop() {
    now = millis();
    
    if(now - lastLDR >= delayLDR) {             //read LDR
        rawVolts = analogRead(LDR_ADC);
        voltsPercent = rawVolts * 100 / 1023;
        lastLDR = now;
    }
    
    if (now - lastIMU >= delayIMU) {            //read IMU
        imu.readAccel(ax, ay, az);
        imu.readGyro(gx, gy, gz);
        lastIMU = now;
    }
    
    btnAraw = digitalRead(BTN_A_PIN);           //read user input buttons
    btnBraw = digitalRead(BTN_B_PIN);
    btnCraw = digitalRead(BTN_C_PIN);
    
    if(readBtnA(now, btnAraw, btnDebounce, btnLongPress)) {
        feedPet(pixelPet);
    }                       
    if(readBtnB(now, btnBraw, btnDebounce, btnLongPress)) {
        playWithPet(pixelPet);
    }
    if(readBtnC(now, btnCraw, btnDebounce, btnLongPress)) {

    }
    checkSleep(pixelPet, )
    decayPetState(pixelPet);

}




