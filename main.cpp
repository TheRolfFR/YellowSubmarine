#include <iostream>
#include "Sensors/SensorBase.h"
#include "Sensors/HumiditySensor.h"
#include "Scheduler/Scheduler.h"
#include "RandomGenerator.h"
#include "Server/Server.h"
#include "Sensors/TemperatureSensor.h"
#include "Sensors/LightSensor.h"
#include "Sensors/PressureSensor.h"
#include <time.h>

int main() {
    RandomGenerator::setSeed(time(NULL));

    HumiditySensor hs("Top Humidity");
    TemperatureSensor inside("Inside temperature");
    LightSensor frontLight("Front lignt");
    PressureSensor outside("Outside pressure");

    std::cout << hs << std::endl;
    std::cout << inside << std::endl;
    std::cout << frontLight << std::endl;
    std::cout << outside << std::endl;

    Server server;

    Scheduler<SensorBase> sch;
    sch.addObject(&inside, 500);
    sch.addObject(&hs, 1000);
    sch.addObject(&frontLight, 5000);
    sch.addObject(&outside, 400);

    sch.run(server);

    return 0;
}