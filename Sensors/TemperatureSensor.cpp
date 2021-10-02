//
// Created by TheRolf on 01/10/2021.
//

#include "TemperatureSensor.h"
#include "../RandomGenerator.h"

SensorData TemperatureSensor::getData() {
    return SensorData(this->getType(), std::to_string(aleaGenVal()) + "\xB0" + "C", this->getId());
}

float TemperatureSensor::aleaGenVal() {
    return RandomGenerator::getFloatInRange(2, -15.69f, 42.05f);
}

std::string TemperatureSensor::print() {
    return this->getReference() + " \"" + this->getName() + "\": " + std::to_string(aleaGenVal()) + " deg C";
}
