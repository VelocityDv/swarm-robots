#include <Arduino.h>
#include "led.h"

int tDelay = 100;
int clearPin = 5;
int dataPin = 6;
int clockPin = 7;
int latchPin = 8;
bool DirectionState = 0;

void initializeOutputs() {
    pinMode(clearPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

    digitalWrite(clearPin, LOW);
    digitalWrite(clearPin, HIGH);
    
}

void updateShiftRegister(byte leds){
    digitalWrite(latchPin, LOW);
    if (DirectionState == false) {
        shiftOut(dataPin, clockPin, LSBFIRST, leds);
    } else {
        shiftOut(dataPin, clockPin, MSBFIRST, leds);
    }
    digitalWrite(latchPin, HIGH);
}

void lightSequence(){
    byte leds = 0B00000000;
    updateShiftRegister(leds);
    delay(tDelay);

    for (int i = 0; i < 8; i++){
        // set the bit i to 1, starting with bit 0, the least significant bit (rightmost bit)
        bitSet(leds, i);
        updateShiftRegister(leds);
        delay(tDelay);
    }
    DirectionState = !DirectionState;
}
