//
// Created by TheRolf on 01/10/2021.
//

#ifndef YELLOWSUBMARINE_LIGHTSENSOR_H
#define YELLOWSUBMARINE_LIGHTSENSOR_H

#include "Sensor.h"

class LightSensor : public Sensor<bool> {
public:
    LightSensor(): Sensor<bool>(LightSensorType) {}
    LightSensor(std::string name): Sensor<bool>(LightSensorType, name) {}
    LightSensor(const LightSensor& o) : Sensor<bool>(o) {}
    LightSensor &operator=(LightSensor& o) {
        Sensor::operator=(o);
        return *this;
    }
    SensorData getData();
    bool aleaGenVal();
    std::string print();
};


#endif //YELLOWSUBMARINE_LIGHTSENSOR_H
