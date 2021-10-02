#include "SensorBase.h"

unsigned int SensorBase::idGenerated = 0;

std::string SensorBase::getReference() {
    return "" + SENSOR_TYPE_NAMES[this->getType()] + "@" + std::to_string(this->getId());
}
