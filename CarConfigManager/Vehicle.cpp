#include "Vehicle.h"

json Vehicle::addConfiguration(json configTemplate) {
    string vehicleWMI;
    string vehicleBrand;
    string vehicleModel;
    string vehicleVIN;
    int vehicleYear;

    cout<<"*****Vehicle Configuration*****\n\n";
    cout<<"Description: "<<configTemplate["Vehicle"]["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["WMI"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>vehicleWMI;
    configTemplate["Vehicle"]["children"]["WMI"]["value"] = vehicleWMI;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Brand"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>vehicleBrand;
    configTemplate["Vehicle"]["children"]["Brand"]["value"] = vehicleBrand;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Model"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>vehicleModel;
    configTemplate["Vehicle"]["children"]["Model"]["value"] = vehicleModel;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["VIN"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>vehicleVIN;
    configTemplate["Vehicle"]["children"]["VIN"]["value"] = vehicleVIN;

    cout<<"\nDescription: "<<configTemplate["Vehicle"]["children"]["Year"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>vehicleYear;
    configTemplate["Vehicle"]["children"]["Year"]["value"] = vehicleYear;

    cout<<"\n\nVehicle configuration added.\n";
    //cout<<setw(4)<<configTemplate["Vehicle"]<<"\n";

    return configTemplate;
}

void Vehicle::viewConfiguration(json vehicleConfiguration) {
    cout << setw(4) << vehicleConfiguration << endl;
}
