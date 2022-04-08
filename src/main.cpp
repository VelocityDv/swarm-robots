#include <Arduino.h>
#include "led.h"

void setup() {
    initializeOutputs();
}


void loop(){
    lightSequence();
}
