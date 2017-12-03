#ifndef CONFIGMANAGER_H_INCLUDED
#define CONFIGMANAGER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "JSONHandler.h"
#include "Vehicle.h"
#include "Body.h"
#include "Cabin.h"
#include "Chasis.h"
#include "Drivetrain.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using json = nlohmann::json;

class ConfigManager:public JSONHandler{

private:
    unsigned int choice;
    string vehicleName;
    char clearScreen[4] = "cls";
    string metadataFilename = "metadata.json";
    json configTemplate;
    json vehicleConfiguration;
    json metadata;
    Vehicle *vehicle;
    Body vehicleBody;
    Cabin vehicleCabin;
    Chasis vehicleChasis;
    Drivetrain vehicleDriveTrain;

public:
    void displayMainMenu();
    void addConfiguration();
    void viewConfiguration();
    void editConfiguration();
};


#endif // CONFIGMANAGER_H_INCLUDED
