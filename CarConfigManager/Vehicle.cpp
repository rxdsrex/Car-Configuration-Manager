#include "Vehicle.h"

void Vehicle::addConfiguration() {
    string vehicleWMI;
    string vehicleBrand;
    string vehicleModel;
    string vehicleVIN;
    int vehicleYear;

    JSONHandler *obj = new JSONHandler();
    this->configTemplate = obj->readFromFile("configTemplate.json");

    cout<<"Description: "<<configTemplate["Vehicle"]["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["WMI"]["description"].get<string>()<<"\n";
    cout<<"Enter WMI: ";
    cin>>vehicleWMI;
    this->configTemplate["Vehicle"]["children"]["WMI"]["value"] = vehicleWMI;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Brand"]["description"].get<string>()<<"\n";
    cout<<"Enter Vehicle Brand: ";
    cin>>vehicleBrand;
    this->configTemplate["Vehicle"]["children"]["Brand"]["value"] = vehicleBrand;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Model"]["description"].get<string>()<<"\n";
    cout<<"Enter Vehicle Model: ";
    cin>>vehicleModel;
    this->configTemplate["Vehicle"]["children"]["Model"]["value"] = vehicleModel;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["VIN"]["description"].get<string>()<<"\n";
    cout<<"Enter VIN: ";
    cin>>vehicleVIN;
    this->configTemplate["Vehicle"]["children"]["Model"]["value"] = vehicleVIN;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Year"]["description"].get<string>()<<"\n";
    cout<<"Enter Year of Manufacture: ";
    cin>>vehicleYear;
    this->configTemplate["Vehicle"]["children"]["Year"]["value"] = vehicleYear;

    cout<<"\n\nVehicle configuration added.\n";
    //cout<<setw(4)<<configTemplate["Vehicle"]<<"\n";
}

json Vehicle::getConfigTemplate() {
    return configTemplate;
}
