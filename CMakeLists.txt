cmake_minimum_required(VERSION 3.20)
project(YellowSubmarine)

set(CMAKE_CXX_STANDARD 14)

add_executable(YellowSubmarine
        main.cpp
        Scheduler/Interval.cpp Scheduler/Interval.h
        Scheduler/IntervalRunnable.cpp Scheduler/IntervalRunnable.h
        Scheduler/Scheduler.cpp Scheduler/Scheduler.h
        Server/Server.cpp Server/Server.h
        Sensors/Constants.h
        Sensors/SensorData.cpp Sensors/SensorData.h
        Sensors/SensorBase.cpp Sensors/SensorBase.h
        Sensors/Sensor.cpp Sensors/Sensor.h
        Sensors/HumiditySensor.cpp Sensors/HumiditySensor.h
        Sensors/LightSensor.cpp Sensors/LightSensor.h
        Sensors/PressureSensor.cpp Sensors/PressureSensor.h
        Sensors/TemperatureSensor.cpp Sensors/TemperatureSensor.h)