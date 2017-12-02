#include "Vehicle.h"

json Vehicle::addConfiguration(json configTemplate) {
    string vehicleWMI;
    string vehicleBrand;
    string vehicleModel;
    string vehicleVIN;
    int vehicleYear;

    cout<<"Description: "<<configTemplate["Vehicle"]["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["WMI"]["description"].get<string>()<<"\n";
    cout<<"Enter WMI: ";
    cin>>vehicleWMI;
    configTemplate["Vehicle"]["children"]["WMI"]["value"] = vehicleWMI;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Brand"]["description"].get<string>()<<"\n";
    cout<<"Enter Vehicle Brand: ";
    cin>>vehicleBrand;
    configTemplate["Vehicle"]["children"]["Brand"]["value"] = vehicleBrand;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Model"]["description"].get<string>()<<"\n";
    cout<<"Enter Vehicle Model: ";
    cin>>vehicleModel;
    configTemplate["Vehicle"]["children"]["Model"]["value"] = vehicleModel;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["VIN"]["description"].get<string>()<<"\n";
    cout<<"Enter VIN: ";
    cin>>vehicleVIN;
    configTemplate["Vehicle"]["children"]["VIN"]["value"] = vehicleVIN;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Year"]["description"].get<string>()<<"\n";
    cout<<"Enter Year of Manufacture: ";
    cin>>vehicleYear;
    configTemplate["Vehicle"]["children"]["Year"]["value"] = vehicleYear;

    cout<<"\n\nVehicle configuration added.\n";
    //cout<<setw(4)<<configTemplate["Vehicle"]<<"\n";

    return configTemplate;
}
