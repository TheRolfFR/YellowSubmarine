#ifndef H_HUMI_SENSOR
#define H_HUMI_SENSOR

#include "Sensor.h"

class HumiditySensor: public Sensor<float> {
  public:
    HumiditySensor(): Sensor<float>(HumiditySensorType) {}
    HumiditySensor(std::string name): Sensor<float>(HumiditySensorType, name) {}
    HumiditySensor(const HumiditySensor& o) : Sensor<float>(o) {}
    HumiditySensor &operator=(HumiditySensor& o) {
      Sensor::operator=(o);
      return *this;
    }
    SensorData getData();
    float aleaGenVal();
    std::string print();
};

#endif