#include "Drivetrain.h"

json Drivetrain::addConfiguration(json configTemplate) {
    int choice;
    int i = 1;
    int gearCount;
    float maxTorque;
    float displacement;
    float maxPower;
    json DriveTypeOptions = configTemplate["Drivetrain"]["children"]["DriveType"]["enum"];
    json TransmissionTypeOptions = configTemplate["Drivetrain"]["children"]["TransmissionType"]["enum"];
    json FuelTypeOptions = configTemplate["Drivetrain"]["children"]["FuelType"]["enum"];

    cout<<"*****Drivetrain Configuration*****\n\n";
    cout<<"Description: "<<configTemplate["Drivetrain"]["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<configTemplate["Drivetrain"]["children"]["DriveType"]["description"].get<string>()<<"\n";
    for(string options : DriveTypeOptions)
        cout << i++ << ". " << options << '\n';
    cout<<"Choose the type: ";
    cin>>choice;
    configTemplate["Drivetrain"]["children"]["DriveType"]["value"] = DriveTypeOptions[choice-1];

    cout<<"\nDescription: "<<configTemplate["Drivetrain"]["children"]["TransmissionType"]["description"].get<string>()<<"\n";
    i = 1;
    for(string options : TransmissionTypeOptions)
        cout << i++ << ". " << options << '\n';
    cout<<"Choose the type: ";
    cin>>choice;
    configTemplate["Drivetrain"]["children"]["TransmissionType"]["value"] = TransmissionTypeOptions[choice-1];

    cout<<"\nDescription: "<<configTemplate["Drivetrain"]["children"]["GearCount"]["description"].get<string>()<<"\n";
    cout<<"Enter the count: ";
    cin>>gearCount;
    configTemplate["Drivetrain"]["children"]["GearCount"]["value"] = gearCount;

    cout<<"\nDescription: "<<configTemplate["Drivetrain"]["children"]["FuelType"]["description"].get<string>()<<"\n";
    i = 1;
    for(string options : FuelTypeOptions)
        cout << i++ << ". " << options << '\n';
    cout<<"Choose the type: ";
    cin>>choice;
    configTemplate["Drivetrain"]["children"]["FuelType"]["value"] = FuelTypeOptions[choice-1];

    cout<<"\nDescription: "<<configTemplate["Drivetrain"]["children"]["MaxTorque"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>maxTorque;
    configTemplate["Drivetrain"]["children"]["MaxTorque"]["value"] = maxTorque;

    cout<<"\nDescription: "<<configTemplate["Drivetrain"]["children"]["Displacement"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>displacement;
    configTemplate["Drivetrain"]["children"]["Displacement"]["value"] = displacement;

    cout<<"\nDescription: "<<configTemplate["Drivetrain"]["children"]["MaxPower"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>maxPower;
    configTemplate["Drivetrain"]["children"]["MaxPower"]["value"] = maxPower;

    cout<<"\n\nDrivetrain configuration added.\n";
    //cout<<setw(4)<<configTemplate["Drivetrain"]<<"\n";

    return configTemplate;
}

void Drivetrain::viewConfiguration(json drivetrainConfiguration) {
    cout<<"*****Drivetrain Configuration*****\n\n";
    cout<<"Description: "<<drivetrainConfiguration["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<drivetrainConfiguration["children"]["DriveType"]["description"].get<string>()<<"\n";
    cout<<"Drive Type: "<<drivetrainConfiguration["children"]["DriveType"]["value"].get<string>()<<"\n";

    cout<<"\nDescription: "<<drivetrainConfiguration["children"]["TransmissionType"]["description"].get<string>()<<"\n";
    cout<<"Transmission Type: "<<drivetrainConfiguration["children"]["TransmissionType"]["value"].get<string>()<<"\n";

    cout<<"\nDescription: "<<drivetrainConfiguration["children"]["GearCount"]["description"].get<string>()<<"\n";
    cout<<"Gear Count: "<<drivetrainConfiguration["children"]["GearCount"]["value"].get<int>()<<"\n";

    cout<<"\nDescription: "<<drivetrainConfiguration["children"]["FuelType"]["description"].get<string>()<<"\n";
    cout<<"Fuel Type: "<<drivetrainConfiguration["children"]["FuelType"]["value"].get<string>()<<"\n";

    cout<<"\nDescription: "<<drivetrainConfiguration["children"]["MaxTorque"]["description"].get<string>()<<"\n";
    cout<<"Max Torque: "<<drivetrainConfiguration["children"]["MaxTorque"]["value"].get<float>()<<"\n\n";

    cout<<"\nDescription: "<<drivetrainConfiguration["children"]["Displacement"]["description"].get<string>()<<"\n";
    cout<<"Displacement: "<<drivetrainConfiguration["children"]["Displacement"]["value"].get<float>()<<"\n\n";

    cout<<"\nDescription: "<<drivetrainConfiguration["children"]["MaxPower"]["description"].get<string>()<<"\n";
    cout<<"Max Power: "<<drivetrainConfiguration["children"]["MaxPower"]["value"].get<float>()<<"\n\n";
    //cout << setw(4) << drivetrainConfiguration << endl;
    system("pause");
}
