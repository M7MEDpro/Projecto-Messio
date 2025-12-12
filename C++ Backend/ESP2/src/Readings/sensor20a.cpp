#include "sensor20a.h"
#include <Arduino.h>

namespace sensor20a {

    
    const int SENSOR_PIN = 33; 
    const float SENSITIVITY = 0.100;
    double voltage = 0;
    double vRMS = 0;
    double AmpsRMS = 0;

    void sensor20a_init() {
        pinMode(SENSOR_PIN, INPUT);
    }

    float getVPP() {
        float result;
        int readValue;             
        int maxValue = 0;         
        int minValue = 4095;    
        
        uint32_t start_time = millis();

        while((millis()-start_time) < 1000) 
        {
            readValue = analogRead(SENSOR_PIN);
            if (readValue > maxValue) 
            {
                maxValue = readValue;
            }
            if (readValue < minValue) 
            {
                minValue = readValue;
            }
        }
        

        result = ((maxValue - minValue) * 3.3) / 4095.0;
        
        return result;
    }

    std::vector<std::pair<String, String>> sensor20a_read() {
        std::vector<std::pair<String, String>> updates;
        
        voltage = getVPP();
        
        vRMS = (voltage / 2.0) * 0.707; 
        

        AmpsRMS = (vRMS * 1000) / 100; /
        float power = 220 * AmpsRMS;
        
        if (power < 0) power = 0;
        

        
        updates.push_back({"S20A", String(power)});
        return updates;
    }
}