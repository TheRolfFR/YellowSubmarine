//
// Created by TheRolf on 01/10/2021.
//

#include <fstream>
#include "Server.h"

void Server::consoleWrite(const SensorData& data) {
    std::cout << data << std::endl;
}

void Server::fileWrite(const SensorData& data) {
    std::ofstream outfile;

    outfile.open(SENSOR_TYPE_NAMES[data.getType()] + ".txt", std::ios_base::app); // append instead of overwrite
    outfile << "@" << data.getSensorId() << ": " << data.getVal() << std::endl;
}

void Server::run(SensorBase *obj) {
    SensorData data = obj->getData();
    this->consoleWrite(data);
    this->fileWrite(data);
}
