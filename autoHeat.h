#ifndef __ARDUINO_AUTO_HEAT_BT__
#define __ARDUINO_AUTO_HEAT_BT__

#include "Arduino.h"
#include "userInt.h"

class AutoHeat: public UserInterfaceBT {
        public:
            AutoHeat(int heatPin, int ventOutPin, int ventInPin, int tempPin, int rx, int tx);
            bool isAutoHeatingOn();
            bool manualHeatingON();
            int autoHeatingON(float setTemperature, float variancet, float temp);
            float getTemperature(int meassureDelay);
            void allDown();
        private:
            bool shouldHeat(float setedTemperature, float variance, float temperature);
            bool shouldVentilate(float setedTemperature, float variance, float temperature);
            bool isTemperatureInRange(float setedTemperature, float variance, float temperature);
       private:
            int _heatPin;
            int _ventInPin;
            int _ventOutPin;
            int _tempPin;  
}; 

#endif
