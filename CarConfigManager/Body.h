#ifndef BODY_H_INCLUDED
#define BODY_H_INCLUDED

#include <iostream>
#include "JSONHandler.h"
#include "json.hpp"
#include "Vehicle.h"

using json = nlohmann::json;


class Body : public Vehicle {

    private:
        json body;
    public:
        void addConfiguration();
};

#endif // BODY_H_INCLUDED
