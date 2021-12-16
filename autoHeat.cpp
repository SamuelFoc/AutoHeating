/*
  AutoHeat.cpp - Library for automated heating using LM35 sensor.
  Created by Samuel Šipikal, December 2, 2021.
  Released into the public domain.
*/
#include "autoHeat.h"


AutoHeat::AutoHeat(int heatPin, int ventOutPin, int ventInPin, int tempPin, int rx, int tx): UserInterfaceBT(rx, tx){
  pinMode(heatPin, OUTPUT);
  _heatPin = heatPin;
  pinMode(ventInPin, OUTPUT);
  _ventInPin = ventInPin;
  pinMode(ventOutPin, OUTPUT);
  _ventOutPin = ventOutPin;
  _tempPin = tempPin;
}

bool AutoHeat::shouldHeat(float setedTemperature, float variance, float temperature){
  if ((setedTemperature - variance - temperature) > 0){return true;}
  else return false;
}

bool AutoHeat::isTemperatureInRange(float setedTemperature, float variance, float temperature){
  if (abs(setedTemperature - temperature) < variance){return true;}
  else return false;
}

bool AutoHeat::shouldVentilate(float setedTemperature, float variance, float temperature){
  if (setedTemperature + variance - temperature < 0){return true;}
  else return false;
}

bool AutoHeat::isAutoHeatingOn(){
      while (available() == 0){
      }
      int numberInput = read();
      if (numberInput == 1){
        bool autoBool = true;
        return autoBool;
      }
      else {
        bool autoBool = false;
        return autoBool;
      };
}

bool AutoHeat::manualHeatingON(){
  while (available() == 0){
  };
      
  if (available() > 0) {
    int intInput = read();
    println(intInput);
    bool flag;
    
  switch (intInput) {
  case 49:
    digitalWrite(_ventInPin, HIGH);
    digitalWrite(_ventOutPin, HIGH);
    flag = true;
    break;
  case 50:
    digitalWrite(_ventInPin, LOW);
    digitalWrite(_ventOutPin, LOW);
    flag = true;
    break;
  case 51:
    digitalWrite(_heatPin, HIGH);
    flag = true;
    break;
  case 52:
    digitalWrite(_heatPin, LOW);
    flag = true;
    break;
  case 53:
    flag = false;
    break;
  }
  return flag;
  };
}

int AutoHeat::autoHeatingON(float setTemperature, float variancet, float temp){
      if (isTemperatureInRange(setTemperature, variancet, temp)){
      digitalWrite(_heatPin, LOW);
      digitalWrite(_ventInPin, LOW);
      digitalWrite(_ventOutPin, LOW);
      return 0;
      }
    else if (shouldHeat(setTemperature, variancet, temp)){
      digitalWrite(_heatPin, HIGH);
      digitalWrite(_ventInPin, LOW);
      digitalWrite(_ventOutPin, LOW);
      return -1;
      }
    else if (shouldVentilate(setTemperature, variancet, temp)){
      digitalWrite(_ventInPin, HIGH);
      digitalWrite(_ventOutPin, HIGH);
      digitalWrite(_heatPin, LOW);
      return 1;
      }
}

float AutoHeat::getTemperature(int meassureDelay){
    float tempSum = 0;
    float meanTemp = 0;
    float rawTemp = 0;
    for (int i = 1; i < 50; i++){
      rawTemp = analogRead(_tempPin);
      tempSum = tempSum + rawTemp;
      meanTemp = tempSum / i;
      delay(meassureDelay);
    }
    float temperature = ( meanTemp/1024.0)*500;
    return temperature;
}

void AutoHeat::allDown(){
      digitalWrite(_heatPin, LOW);
      digitalWrite(_ventInPin, LOW);
      digitalWrite(_ventOutPin, LOW);
}

  
