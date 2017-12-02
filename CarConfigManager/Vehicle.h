#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include <unordered_map>
#include "JSONHandler.h"
#include "json.hpp"

using json = nlohmann::json;

class Vehicle {

private:
    json configTemplate;
public:
    virtual void addConfiguration();
    json getConfigTemplate();
};

#endif // VEHICLE_H_INCLUDED
