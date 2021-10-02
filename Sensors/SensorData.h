#ifndef H_SENSOR_DATA
#define H_SENSOR_DATA

#include "Constants.h"
#include <iostream>
#include <string>

class SensorData {
  private:
    SensorType type;
    std::string val;
    int sensorId;
  public:
    SensorData() : type(), val(), sensorId() {}
    SensorData(SensorType type, std::string val, int sensorId) : type(type), val(val), sensorId(sensorId) {}
    SensorData(const SensorData& d) : type(d.type), val(d.val), sensorId(d.sensorId) {}
    SensorData &operator=(const SensorData& o) {
      this->type = o.type;
      this->val = o.type;
      return *this;
    }
    virtual ~SensorData() {}

    SensorType getType() const {
    	return this->type;
    }

    std::string getVal() const {
    	return this->val;
    }

    int getSensorId() const {
        return sensorId;
    }
};

inline
std::ostream& operator<<(std::ostream& os, SensorData data)
{
    os << SENSOR_TYPE_NAMES[data.getType()] << "@" << data.getSensorId() << ": " << data.getVal();
    return os;
}

#endif