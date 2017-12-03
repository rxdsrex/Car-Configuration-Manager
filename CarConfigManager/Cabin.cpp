#include "Cabin.h"

json Cabin::addConfiguration(json configTemplate) {
    int choice;
    int i = 1;
    int doorCount;
    json steeringWheelPositionOptions = configTemplate["Cabin"]["children"]["SteeringWheelPosition"]["enum"];

    cout<<"*****Cabin Configuration*****\n\n";
    cout<<"Description: "<<configTemplate["Cabin"]["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<configTemplate["Cabin"]["children"]["DoorCount"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>doorCount;
    configTemplate["Cabin"]["children"]["DoorCount"]["value"] = doorCount;

    cout<<"\nDescription: "<<configTemplate["Cabin"]["children"]["SteeringWheelPosition"]["description"].get<string>()<<"\n";
    for(string options : steeringWheelPositionOptions)
        cout << i++ << ". " << options << '\n';
    cout<<"Choose the position: ";
    cin>>choice;
    configTemplate["Cabin"]["children"]["SteeringWheelPosition"]["value"] = steeringWheelPositionOptions[choice-1];

    cout<<"\n\nCabin configuration added.\n";
    //cout<<setw(4)<<configTemplate["Cabin"]<<"\n";

    return configTemplate;
}
