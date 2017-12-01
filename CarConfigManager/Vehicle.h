#ifndef VEHICLE_H_INCLUDED
#define VEHICLE_H_INCLUDED

#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

class Vehicle{

private:
    json vehicle;
public:
    Vehicle(int idArray[]) {
        for(int id : idArray) {
            this->vehicle[33] = value;
        }
    }
};

#endif // VEHICLE_H_INCLUDED
