#ifndef CABIN_H_INCLUDED
#define CABIN_H_INCLUDED

#include <iostream>
#include "json.hpp"
#include "Vehicle.h"

using json = nlohmann::json;

class Cabin : public Vehicle {

    private:
        json cabin;
    public:
        json addConfiguration(json);

};

#endif // CABIN_H_INCLUDED
