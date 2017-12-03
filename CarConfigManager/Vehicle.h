#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Vehicle {
private:
    json vehicleJSON;
public:
    virtual json addConfiguration(json);
    virtual void viewConfiguration(json);
};

#endif // VEHICLE_H_INCLUDED
