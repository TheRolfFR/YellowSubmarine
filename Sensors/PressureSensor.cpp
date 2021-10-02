//
// Created by TheRolf on 01/10/2021.
//

#include "PressureSensor.h"
#include "../RandomGenerator.h"

SensorData PressureSensor::getData() {
    return SensorData(this->getType(), std::to_string(aleaGenVal()) + " millibars", this->getId());
}

int PressureSensor::aleaGenVal() {
    return RandomGenerator::getIntInRange(800, 3000);
}

std::string PressureSensor::print() {
    return this->getReference() + " \"" + this->getName() + "\": " + std::to_string(aleaGenVal()) + " millibars";
}
