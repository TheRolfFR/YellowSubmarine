#include <string>
#include "HumiditySensor.h"
#include "../RandomGenerator.h"

SensorData HumiditySensor::getData() {
  return SensorData(this->getType(), std::to_string(aleaGenVal()) + "%", this->getId());
}

float HumiditySensor::aleaGenVal() {
  return RandomGenerator::getFloatInRange(2, 0, 101);
}

std::string HumiditySensor::print() {
    return this->getReference() + " \"" + this->getName() + "\": " + std::to_string(aleaGenVal()) + "%";
}
