#pragma once

struct petState {
  int hunger = 80;
  int happiness = 80;
  bool isAsleep = false;
  unsigned long lastUpdate = 0;
};

void decayPetState(petState &state);
void feedPet(petState &state);
void playWithPet(petState &state);
void checkSleep(petState &state, bool dark);