#pragma once

#include <SPI.h>
#include <7Semi_BMI323.h>

//pin assignments
const int SPI_MOSI = 11;
const int SPI_MISO = 13;
const int SPI_SCK = 20;

const int IMU_CS = 10;

const int LDR_ADC = 4;

const int BUZZ_PWM_PIN = 31;

const int BTN_A_PIN = 14;
const int BTN_B_PIN = 2;
const int BTN_C_PIN = 1;

const int BTN_RESET_PIN = 3;
const int BTN_BOOT_PIN = 0;

BMI323_7Semi imu;

unsigned long now;

//imu measurements
unsigned long lastIMU = 0;
int delayIMU = 300;
int calibDelayIMU = 2000;
float ax, ay, az;
float gx, gy, gz;

//LDR measurements
unsigned long lastLDR = 0;
int delayLDR = 500;
int rawVolts;
int voltsPercent;

//button values
bool btnBoot;

bool btnAraw;
bool btnBraw;
bool btnCraw;
bool btnA;
bool btnB;
bool btnC;
int btnDebounce = 50;
int btnLongPress = 100;
