#ifndef H_SENSOR_BASE
#define H_SENSOR_BASE

#include "Constants.h"
#include "SensorData.h"

class SensorBase {
  private:
    SensorType type;
    int id;
    std::string name;

    static unsigned int idGenerated; ///< ID Unique pour un sensor

    /**
     * Système de génération d'identifiants uniques,
     * prend le courant et incrémente
     * @return Unique ID
     */
    static unsigned int getNewId() {
      int result = idGenerated;
      ++idGenerated;
      return result;
    }

  public:
    SensorBase(): type(UnknownSensorType), id(this->getNewId()), name("") {}
    SensorBase(SensorType t): type(t), id(this->getNewId()), name("") {}
    SensorBase(SensorType t, std::string name) : type(t), id(this->getNewId()), name(name) {}
    SensorBase(const SensorBase& o) : id(o.id), name(o.name), type(o.type) {}
    SensorBase &operator=(const SensorBase& o) {
      this->id = o.id;
      this->name = o.name;
      this->type = o.type;
      
      return *this;
    }

    virtual SensorData getData() = 0;
    virtual std::string print() = 0;

    SensorType getType() {
      return this->type;
    }

    int getId() {
      return this->id;
    }

    std::string getName() {
      return this->name;
    }

    std::string getReference(); // joli nom pour savoir de quoi et qui on parle (type et id)
};

// cette fonction, combinée à la méthode print virtuelle, fournit un opérateur de sortie à toutes les classes filles
inline
std::ostream& operator<<(std::ostream& os, SensorBase& base) {
    os << base.print();
    return os;
}

#endif