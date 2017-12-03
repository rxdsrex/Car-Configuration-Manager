#ifndef CABIN_H_INCLUDED
#define CABIN_H_INCLUDED

#include "Vehicle.h"

using json = nlohmann::json;

class Cabin : public Vehicle {
private:
    json cabin;
public:
    json addConfiguration(json);
    void viewConfiguration(json);
    json editConfiguration(json);
};

#endif // CABIN_H_INCLUDED
