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
