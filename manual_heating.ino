#include <Wire.h>
#include "autoHeat.h"

//Pins definitions
#define heatPin 6
#define ventOutPin 7
#define ventInPin 8
#define tempSensPin A0
#define rx 2
#define tx 3

//Variables declaring
AutoHeat autoBT(heatPin, ventOutPin, ventInPin, tempSensPin, rx, tx);

void setup() {
  autoBT.begin(9600);
}

void loop() {
    autoBT.manualHeatingON();
}
