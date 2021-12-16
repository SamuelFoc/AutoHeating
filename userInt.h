#ifndef __ARDUINO_AUTO_HEAT_BT_UI__
#define __ARDUINO_AUTO_HEAT_BT_UI__

#include <Arduino.h>
#include <SoftwareSerial.h>

class UserInterfaceBT: public SoftwareSerial {
    public:
        UserInterfaceBT(int rx, int tx);
        void printActualTemperature(float temperature);
        void printManualMode();
        float setVariance();
        float setTemperature();
};

#endif
