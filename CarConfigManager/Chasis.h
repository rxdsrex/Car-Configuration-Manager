#ifndef CHASIS_H_INCLUDED
#define CHASIS_H_INCLUDED

#include <iostream>
#include "json.hpp"
#include "Vehicle.h"

using json = nlohmann::json;

class Chasis : public Vehicle {

    private:
        json chasis;
    public:
        void addConfiguration();

};

#endif // CHASIS_H_INCLUDED
