//
// Created by TheRolf on 01/10/2021.
//

#ifndef YELLOWSUBMARINE_PRESSURESENSOR_H
#define YELLOWSUBMARINE_PRESSURESENSOR_H

#include "Sensor.h"

class PressureSensor : public Sensor<int> {
  public:
    PressureSensor(): Sensor<int>(PressureSensorType) {}
    PressureSensor(std::string name): Sensor<int>(PressureSensorType, name) {}
    PressureSensor(const PressureSensor& o) : Sensor<int>(o) {}
    PressureSensor &operator=(PressureSensor& o) {
        Sensor::operator=(o);
        return *this;
    }
    SensorData getData();
    int aleaGenVal();
    std::string print();
};



#endif //YELLOWSUBMARINE_PRESSURESENSOR_H
