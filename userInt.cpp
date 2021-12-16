#include "userInt.h"

UserInterfaceBT::UserInterfaceBT(int rx, int tx): SoftwareSerial(rx, tx){};

void UserInterfaceBT::printActualTemperature(float temperature){
    print("Temperature is: ");
    print(temperature);
    print(" degrees Celsius");
    println();
}

void UserInterfaceBT::printManualMode(){
  println("%%%%%%%%%%%%%");
  println("MANUAL MODE");
  println("%%%%%%%%%%%%%");
  println("Waiting for input...");
  println("Input:");
  println("1  for ventilating ON");
  println("2  for ventilating OFF");
  println("3  for heating ON");
  println("4  for heating OFF");
  println("5  for turn OFF the Manual mode");
  println();
}

float UserInterfaceBT::setVariance(){
      println("Set variance of temperature...");
 
      while (available() == 0){
        println("...");
        delay(5000);
      }
      
      if (available()>0) {
        String numberInput = readString();
        float variance = numberInput.toInt();
        print("Temperature variance is set to: ");
        delay(500);
        print(variance);
        println(" degrees Celsius");
        delay(500);
        return variance;
      }
}

float UserInterfaceBT::setTemperature(){
      println("Set temperature inside room...");

      while (available() == 0){
        println("...");
        delay(5000);
      }
      
      if (available()>0) {
        String numberInput = readString();
        float temperature = numberInput.toInt();
        print("Indoor temperature is set to: ");
        delay(50);
        print(temperature);
        println(" degrees Celsius");
        delay(50);
        return temperature;
      } 
}
