#ifndef DRIVETRAIN_H_INCLUDED
#define DRIVETRAIN_H_INCLUDED

#include <iostream>
#include "json.hpp"
#include "Vehicle.h"

using json = nlohmann::json;

class Drivetrain : public Vehicle {
private:
    json drivetrain;
public:
    json addConfiguration(json);
};

#endif // DRIVETRAIN_H_INCLUDED
