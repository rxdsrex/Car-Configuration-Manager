#ifndef CONFIGMANAGER_H_INCLUDED
#define CONFIGMANAGER_H_INCLUDED

#include <iostream>
#include "JSONHandler.h"
#include "ConfigManager.h"
#include "Body.h"
#include "Cabin.h"
#include "Chasis.h"
#include "Drivetrain.h"
#include "Sensor.h"

//using namespace std;
using json = nlohmann::json;

class ConfigManager:public JSONHandler{

};


#endif // CONFIGMANAGER_H_INCLUDED
