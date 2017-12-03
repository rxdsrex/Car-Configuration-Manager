#ifndef DRIVETRAIN_H_INCLUDED
#define DRIVETRAIN_H_INCLUDED

#include "Vehicle.h"

using json = nlohmann::json;

class Drivetrain : public Vehicle {
public:
    json addConfiguration(json);
    void viewConfiguration(json);
    json editConfiguration(json);
};

#endif // DRIVETRAIN_H_INCLUDED
