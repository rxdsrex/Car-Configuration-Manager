#ifndef CHASIS_H_INCLUDED
#define CHASIS_H_INCLUDED

#include "Vehicle.h"

using json = nlohmann::json;

class Chasis : public Vehicle {
private:
    json chasis;
public:
    json addConfiguration(json);
    void viewConfiguration(json);
    json editConfiguration(json);
};

#endif // CHASIS_H_INCLUDED
