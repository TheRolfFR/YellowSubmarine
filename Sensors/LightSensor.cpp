//
// Created by TheRolf on 01/10/2021.
//

#include "LightSensor.h"
#include "../RandomGenerator.h"

SensorData LightSensor::getData() {
    return SensorData(this->getType(), std::to_string(aleaGenVal()), this->getId());
}

bool LightSensor::aleaGenVal() {
    return RandomGenerator::getBoolean();
}

std::string LightSensor::print() {
    return this->getReference() + " \"" + this->getName() + "\": " + std::to_string(aleaGenVal());
}
