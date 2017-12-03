#include "Body.h"

json Body::addConfiguration(json configTemplate) {
    int choice;
    int i = 1;
    json refuelOptions = configTemplate["Body"]["children"]["RefuelPosition"]["enum"];
    json BodyOptions = configTemplate["Body"]["children"]["BodyType"]["enum"];

    cout<<"*****Body Configuration*****\n\n";
    cout<<"Description: "<<configTemplate["Body"]["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<configTemplate["Body"]["children"]["RefuelPosition"]["description"].get<string>()<<"\n";
    for(string options : refuelOptions)
        cout << i++ << ". " << options << '\n';
    cout<<"Choose the position: ";
    cin>>choice;
    configTemplate["Body"]["children"]["RefuelPosition"]["value"] = refuelOptions[choice-1];

    cout<<"\nDescription: "<<configTemplate["Body"]["children"]["BodyType"]["description"].get<string>()<<"\n";
    i = 1;
    for(string options : BodyOptions)
        cout << i++ << ". " << options << '\n';
    cout<<"Choose the type: ";
    cin>>choice;
    configTemplate["Body"]["children"]["BodyType"]["value"] = BodyOptions[choice-1];

    cout<<"\n\nBody configuration added.\n";
    //cout<<setw(4)<<configTemplate["Body"]<<"\n";

    return configTemplate;

}

void Body::viewConfiguration(json bodyConfiguration) {
    cout<<"*****Body Configuration*****\n\n";
    cout<<"Description: "<<bodyConfiguration["description"].get<string>()<<"\n";

    cout<<"\nDescription: "<<bodyConfiguration["children"]["RefuelPosition"]["description"].get<string>()<<"\n";
    cout<<"Refuel Position: "<<bodyConfiguration["children"]["RefuelPosition"]["value"].get<string>()<<"\n";

    cout<<"\nDescription: "<<bodyConfiguration["children"]["BodyType"]["description"].get<string>()<<"\n";
    cout<<"BodyType: "<<bodyConfiguration["children"]["BodyType"]["value"].get<string>()<<"\n\n";

    //cout << setw(4) << bodyConfiguration << endl;
    system("pause");
}

json Body::editConfiguration(json bodyConfiguration) {
    int i;
    int flag = 1;
    string exit;
    string editName;
    int intData;
    string stringData;
    int choice;
    json bodyAttributes;
    for (auto it = bodyConfiguration["children"].begin(); it != bodyConfiguration["children"].end(); ++it)
        bodyAttributes.emplace_back(string(it.key()));
    do {
        system("cls");
        cout << "*****Edit Body Configuration*****\n\n";
        cout << "Current values:\n";
        i = 1;
        for(string options : bodyAttributes){
            cout << i++ << ". " << options << ": "<<bodyConfiguration["children"][options]["value"] << "\n";
        }
        cout << "Choose an option: ";
        cin>>choice;
        editName = bodyAttributes[choice-1];
        if(bodyConfiguration["children"][editName]["value"].is_string()) {
            if(bodyConfiguration["children"][editName]["hasEnum"] == true) {
                json options = bodyConfiguration["children"][editName]["enum"];
                i = 1;
                for(string option : options)
                    cout << i++ << ". " << option << '\n';
                cout<<"Choose an option: ";
                cin>>intData;
                bodyConfiguration["children"][editName]["value"] = options[intData - 1];
                cout << "\nValue changed\n";
            }
            else {
                cout << "Enter the new value: ";
                cin >> stringData;
                bodyConfiguration["children"][editName]["value"] = stringData;
                cout << "\nValue changed\n";
            }
        }
        cout<<"Enter x and return key to exit.. ";
        cin>>exit;
        if(exit == "x")
            flag = 0;
    }while(flag);
    return bodyConfiguration;
}
