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

void Cabin::viewConfiguration(json cabinConfiguration) {
    cout<<"*****Cabin Configuration*****\n\n";
    cout<<"Description: "<<cabinConfiguration["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<cabinConfiguration["children"]["DoorCount"]["description"].get<string>()<<"\n";
    cout<<"Door Count: "<<cabinConfiguration["children"]["DoorCount"]["value"].get<int>()<<"\n";

    cout<<"\nDescription: "<<cabinConfiguration["children"]["SteeringWheelPosition"]["description"].get<string>()<<"\n";
    cout<<"Steering Wheel Position: "<<cabinConfiguration["children"]["SteeringWheelPosition"]["value"].get<string>()<<"\n\n";

    //cout << setw(4) << cabinConfiguration << endl;
    system("pause");
}

json Cabin::editConfiguration(json cabinConfiguration) {
    int i;
    int flag = 1;
    string exit;
    string editName;
    int intData;
    string stringData;
    int choice;
    json cabinAttributes;
    for (auto it = cabinConfiguration["children"].begin(); it != cabinConfiguration["children"].end(); ++it)
        cabinAttributes.emplace_back(string(it.key()));
    do {
        system("cls");
        cout << "*****Edit Cabin Configuration*****\n\n";
        cout << "Current values:\n";
        i = 1;
        for(string options : cabinAttributes){
            cout << i++ << ". " << options << ": "<<cabinConfiguration["children"][options]["value"] << "\n";
        }
        cout << "Choose an option: ";
        cin>>choice;
        editName = cabinAttributes[choice-1];
        if(cabinConfiguration["children"][editName]["value"].is_number_integer()) {
            cout << "Enter the new value: ";
            cin >> intData;
            cabinConfiguration["children"][editName]["value"] = intData;
            cout << "\nValue changed\n";
        }
        else if(cabinConfiguration["children"][editName]["value"].is_string()) {
            if(cabinConfiguration["children"][editName]["hasEnum"] == true) {
                json options = cabinConfiguration["children"][editName]["enum"];
                i = 1;
                for(string option : options)
                    cout << i++ << ". " << option << '\n';
                cout<<"Choose an option: ";
                cin>>intData;
                cabinConfiguration["children"][editName]["value"] = options[intData - 1];
                cout << "\nValue changed\n";
            }
            else {
                cout << "Enter the new value: ";
                cin >> stringData;
                cabinConfiguration["children"][editName]["value"] = stringData;
                cout << "\nValue changed\n";
            }
        }
        cout<<"Enter x and return key to exit.. ";
        cin>>exit;
        if(exit == "x")
            flag = 0;
    }while(flag);
    return cabinConfiguration;
}
