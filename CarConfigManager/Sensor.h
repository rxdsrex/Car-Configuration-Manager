#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

#include <iostream>
#include "json.hpp"
#include "Vehicle.h"

using json = nlohmann::json;

class Sensor : public Vehicle {

    private:
        json sensor;
    public:
        void addConfiguration();
};

#endif // SENSOR_H_INCLUDED
