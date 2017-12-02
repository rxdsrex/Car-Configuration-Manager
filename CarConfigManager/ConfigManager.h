#ifndef CONFIGMANAGER_H_INCLUDED
#define CONFIGMANAGER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "JSONHandler.h"
#include "Vehicle.h"
#include "Body.h"
#include "Cabin.h"
#include "Chasis.h"
#include "Drivetrain.h"
#include "Sensor.h"

using namespace std;

using json = nlohmann::json;

class ConfigManager:public JSONHandler{

private:
    int choice;
    string vehicleName;
    Vehicle *vehicle;
    Sensor vehicleSensor;
    Body vehicleBody;
    Cabin vehicleCabin;
    Chasis vehicleChasis;
    Drivetrain vehicleDriveTrain;

public:
    void displayMainMenu();
    void addConfiguration();
    void viewConfiguration();
    void listAllConfigurations();
};


#endif // CONFIGMANAGER_H_INCLUDED
