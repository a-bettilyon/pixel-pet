#include <Arduino.h>


bool readBtnA(unsigned long time, bool b1raw, int delay, int longpress) {
  static bool lastB1Raw;
  static unsigned long lastToggleMs1;
  static bool repeating;
  static unsigned long lastRepeat1;
  int b1Final;  //0=no press, 1=short press, 2=long press

  if (b1raw == LOW && lastB1Raw == HIGH) {
    lastToggleMs1 = time;
    b1Final = 0;
  }  //detect button pressed (falling edge), record time, set b1 final status

  if ((b1raw == HIGH) && (lastB1Raw == LOW)) {                                         //if button 1 was short-pressed: button is currently HIGH , was last LOW
    if (((time - lastToggleMs1) > (delay)) && ((time - lastToggleMs1) < longpress)) {  //if time from press to release is greater than debounce but less than longPress (repeat threshold)
      repeating = false;
      b1Final = 1;
    }
    repeating = false;
  }
  if (((time - lastToggleMs1) > (longpress)) && (b1raw == LOW)) {  //if time since press is greater than longpress and the button was not short pressed
    if (!repeating) {
      repeating = true;
      lastRepeat1 = time;
      b1Final = 2;
    }
    if ((time - lastRepeat1) >= longpress) {
      lastRepeat1 = time;
      b1Final = 2;
    }
  }
  lastB1Raw = b1raw;
  return b1Final;
}

bool readBtnB(unsigned long time, bool b2raw, int delay, int longpress) {
  static bool lastB2Raw;
  static unsigned long lastToggleMs2;
  static bool repeating;
  static unsigned long lastRepeat2;
  int b2Final;  //0=no press, 1=short press, 2=long press

  if (b2raw == LOW && lastB2Raw == HIGH) {
    lastToggleMs2 = time;
    b2Final = 0;
  }  //detect button pressed (falling edge), record time, set b2 final status

  if ((b2raw == HIGH) && (lastB2Raw == LOW)) {                                         //if button 2 was short-pressed: button is currently HIGH , was last LOW
    if (((time - lastToggleMs2) > (delay)) && ((time - lastToggleMs2) < longpress)) {  //if time from press to release is greater than debounce but less than longPress (repeat threshold)

      repeating = false;
      b2Final = 1;
    }
    repeating = false;
  }
  if (((time - lastToggleMs2) > (longpress)) && (b2raw == LOW)) {  //if time since press is greater than longpress and the button was not short pressed
    if (!repeating) {
      repeating = true;
      lastRepeat2 = time;
      b2Final = 2;
    }
    if ((time - lastRepeat2) >= longpress) {
      lastRepeat2 = time;
      b2Final = 2;
    }
  }
  lastB2Raw = b2raw;
  return b2Final;
}

bool readBtnC(unsigned long time, bool b3raw, int delay, int longpress) {
  static bool lastB3Raw;
  static unsigned long lastToggleMs3;
  static bool repeating;
  static unsigned long lastRepeat3;
  int b3Final;  //0=no press, 1=short press, 2=long press

  if (b3raw == LOW && lastB3Raw == HIGH) {
    lastToggleMs3 = time;
    b3Final = 0;
  }  //detect button pressed (falling edge), record time, set b3 final status

  if ((b3raw == HIGH) && (lastB3Raw == LOW)) {                                         //if button 3 was short-pressed: button is currently HIGH , was last LOW
    if (((time - lastToggleMs3) > (delay)) && ((time - lastToggleMs3) < longpress)) {  //if time from press to release is greater than debounce but less than longPress (repeat threshold)
      repeating = false;
      b3Final = 1;
    }
    repeating = false;
  }
  if (((time - lastToggleMs3) > (longpress)) && (b3raw == LOW)) {  //if time since press is greater than longpress and the button was not short pressed
    if (!repeating) {
      repeating = true;
      lastRepeat3 = time;
      b3Final = 2;
    }
    if ((time - lastRepeat3) >= longpress) {
      lastRepeat3 = time;
      b3Final = 2;
    }
  }
  lastB3Raw = b3raw;
  return b3Final;
}

