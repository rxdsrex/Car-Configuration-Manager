#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Vehicle {
public:
    virtual json addConfiguration(json);
    virtual void viewConfiguration(json);
    virtual json editConfiguration(json);
};

#endif // VEHICLE_H_INCLUDED
