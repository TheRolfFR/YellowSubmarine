//
// Created by TheRolf on 01/10/2021.
//

#ifndef YELLOWSUBMARINE_SERVER_H
#define YELLOWSUBMARINE_SERVER_H


#include "../Sensors/SensorBase.h"
#include "../Scheduler/IntervalRunnable.h"

class Server : public IntervalRunnable<SensorBase> {
    public:
        Server() {}
        Server(const Server& server) {}
        Server &operator=(const Server& server) { return *this; }
        virtual ~Server() {}

        void consoleWrite(const SensorData&);
        void fileWrite(const SensorData&);
        void run(SensorBase *);
};


#endif //YELLOWSUBMARINE_SERVER_H
