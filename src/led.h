#ifndef LED_H
#define LED_H

#include <Arduino.h>

extern int tDelay;
extern int clearPin;
extern int dataPin;
extern int clockPin; 
extern int latchPin;
extern bool DirectionState;

void initializeOutputs();
void updateShiftRegister(byte leds);
void lightSequence();

#endif