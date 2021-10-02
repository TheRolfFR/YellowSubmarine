#ifndef H_SENSOR_CONSTANTS
#define H_SENSOR_CONSTANTS

#include <string>

typedef enum {
  UnknownSensorType,
  HumiditySensorType,
  TemperatureSensorType,
  LightSensorType,
  PressureSensorType
} SensorType;

const std::string SENSOR_TYPE_NAMES[] = {
  "UNKNOWN",
  "HUMI",
  "TEMP",
  "LIGHT",
  "PRESSURE"
};

#endif