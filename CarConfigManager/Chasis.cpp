#include "Chasis.h"

json Chasis::addConfiguration(json configTemplate) {
    float grossWeight;
    int wheelbase;
    int height;
    int width;
    int length;
    float curbWeight;

    cout<<"*****Chassis Configuration*****\n\n";
    cout<<"Description: "<<configTemplate["Chassis"]["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<configTemplate["Chassis"]["children"]["GrossWeight"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>grossWeight;
    configTemplate["Chassis"]["children"]["GrossWeight"]["value"] = grossWeight;

    cout<<"\nDescription: "<<configTemplate["Chassis"]["children"]["Wheelbase"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>wheelbase;
    configTemplate["Chassis"]["children"]["Wheelbase"]["value"] = wheelbase;

    cout<<"\nDescription: "<<configTemplate["Chassis"]["children"]["Height"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>height;
    configTemplate["Chassis"]["children"]["Height"]["value"] = height;

    cout<<"\nDescription: "<<configTemplate["Chassis"]["children"]["Width"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>width;
    configTemplate["Chassis"]["children"]["Width"]["value"] = width;

    cout<<"\nDescription: "<<configTemplate["Chassis"]["children"]["Length"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>length;
    configTemplate["Chassis"]["children"]["Length"]["value"] = length;

    cout<<"\nDescription: "<<configTemplate["Chassis"]["children"]["CurbWeight"]["description"].get<string>()<<"\n";
    cout<<"Enter the value: ";
    cin>>curbWeight;
    configTemplate["Chassis"]["children"]["CurbWeight"]["value"] = curbWeight;

    cout<<"\n\nChassis configuration added.\n";
    //cout<<setw(4)<<configTemplate["Chassis"]<<"\n";

    return configTemplate;
}

void Chasis::viewConfiguration(json chassisConfiguration) {
    cout<<"*****Chassis Configuration*****\n\n";
    cout<<"Description: "<<chassisConfiguration["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<chassisConfiguration["children"]["GrossWeight"]["description"].get<string>()<<"\n";
    cout<<"Gross Weight: "<<chassisConfiguration["children"]["GrossWeight"]["value"].get<float>()<<"\n";

    cout<<"\nDescription: "<<chassisConfiguration["children"]["Wheelbase"]["description"].get<string>()<<"\n";
    cout<<"Wheelbase: "<<chassisConfiguration["children"]["Wheelbase"]["value"].get<int>()<<"\n";

    cout<<"\nDescription: "<<chassisConfiguration["children"]["Height"]["description"].get<string>()<<"\n";
    cout<<"Height: "<<chassisConfiguration["children"]["Height"]["value"].get<int>()<<"\n";

    cout<<"\nDescription: "<<chassisConfiguration["children"]["Width"]["description"].get<string>()<<"\n";
    cout<<"Width: "<<chassisConfiguration["children"]["Width"]["value"].get<int>()<<"\n";

    cout<<"\nDescription: "<<chassisConfiguration["children"]["Length"]["description"].get<string>()<<"\n";
    cout<<"Length: "<<chassisConfiguration["children"]["Length"]["value"].get<int>()<<"\n";

    cout<<"\nDescription: "<<chassisConfiguration["children"]["CurbWeight"]["description"].get<string>()<<"\n";
    cout<<"Curb Weight: "<<chassisConfiguration["children"]["CurbWeight"]["value"].get<float>()<<"\n\n";

    //cout << setw(4) << chassisConfiguration << endl;
    system("pause");
}

json Chasis::editConfiguration(json chassisConfiguration) {
    int i;
    int flag = 1;
    string exit;
    string editName;
    int intData;
    float floatData;
    int choice;
    json chassisAttributes;
    for (auto it = chassisConfiguration["children"].begin(); it != chassisConfiguration["children"].end(); ++it)
        chassisAttributes.emplace_back(string(it.key()));
    do {
        system("cls");
        cout << "*****Edit Chassis Configuration*****\n\n";
        cout << "Current values:\n";
        i = 1;
        for(string options : chassisAttributes){
            cout << i++ << ". " << options << ": "<<chassisConfiguration["children"][options]["value"] << "\n";
        }
        cout << "Choose an option: ";
        cin>>choice;
        editName = chassisAttributes[choice-1];
        cout << "Enter the new value: ";
        if(chassisConfiguration["children"][editName]["value"].is_number_integer()) {
            cin >> intData;
            chassisConfiguration["children"][editName]["value"] = intData;
            cout << "\nValue changed\n";
        }
        else if(chassisConfiguration["children"][editName]["value"].is_number_float()) {
            cin >> floatData;
            chassisConfiguration["children"][editName]["value"] = floatData;
            cout << "\nValue changed\n";
        }
        cout<<"Enter x and return key to exit.. ";
        cin>>exit;
        if(exit == "x")
            flag = 0;
    }while(flag);
    return chassisConfiguration;
}
