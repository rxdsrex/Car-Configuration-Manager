#ifndef BODY_H_INCLUDED
#define BODY_H_INCLUDED

#include "JSONHandler.h"
#include "json.hpp"
#include "Vehicle.h"

using json = nlohmann::json;


class Body : public Vehicle {
private:
    json bodyConfiguration;
public:
    json addConfiguration(json);
};

#endif // BODY_H_INCLUDED
