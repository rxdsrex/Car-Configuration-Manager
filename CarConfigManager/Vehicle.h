#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include "JSONHandler.h"
#include "json.hpp"

using json = nlohmann::json;

class Vehicle : public JSONHandler {

private:
    json vehicle;
public:
    virtual void addConfiguration();

};

#endif // VEHICLE_H_INCLUDED
