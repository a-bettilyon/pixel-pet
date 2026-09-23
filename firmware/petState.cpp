#include <Arduino.h>
#include "petState.h"


const unsigned long statDecayInterval = 60000;
int hungerInterval = 5;
int happinessInterval = 5;

void decayPetState(petState &state) {
  unsigned long now = millis();

  if(now - state.lastUpdate >= statDecayInterval) {
    state.hunger = constrain((state.hunger - hungerInterval), 0, 100);
    state.happiness = constrain((state.happiness - happinessInterval), 0, 100);
    state.lastUpdate = now;
  }
}

void feedPet(petState &state) {
  state.hunger = constrain((state.hunger + hungerInterval), 0, 100);
}

void playWithPet(petState &state) {
  state.happiness = constrain((state.happiness + happinessInterval), 0, 100);
}

void checkSleep(petState &state, bool dark) {
  state.isAsleep = dark;
}