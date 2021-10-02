#ifndef H_SENSOR
#define H_SENSOR

#include "SensorBase.h"

template<typename T> class Sensor : public SensorBase {
  public:
    Sensor(): SensorBase() {}
    Sensor(SensorType t): SensorBase (t) {}
    Sensor(SensorType t, std::string name) : SensorBase(t, name) {}
    Sensor(const Sensor& o) : SensorBase(o) {}
    Sensor<T> &operator=(const Sensor<T>& o) {
      SensorBase::operator=(o); // opérateur égal parent
      return *this;
    }
  protected:
    virtual T aleaGenVal() = 0; // permet de forcer l'implémentation de génération de valeur aléatoire
};

#endif