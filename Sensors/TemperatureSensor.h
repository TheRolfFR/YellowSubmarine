//
// Created by TheRolf on 01/10/2021.
//

#ifndef YELLOWSUBMARINE_TEMPERATURESENSOR_H
#define YELLOWSUBMARINE_TEMPERATURESENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor<float> {
public:
    TemperatureSensor(): Sensor<float>(TemperatureSensorType) {}
    TemperatureSensor(std::string name): Sensor<float>(TemperatureSensorType, name) {}
    TemperatureSensor(const TemperatureSensor& o) : Sensor<float>(o) {}
    TemperatureSensor &operator=(TemperatureSensor& o) {
        Sensor::operator=(o);
        return *this;
    }
    SensorData getData();
    float aleaGenVal();
    std::string print();
};


#endif //YELLOWSUBMARINE_TEMPERATURESENSOR_H
