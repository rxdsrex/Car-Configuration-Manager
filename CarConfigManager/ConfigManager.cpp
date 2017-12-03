#include "ConfigManager.h"

void ConfigManager::displayMainMenu() {
    system(clearScreen);
    cout<<"====== VEHICLE CONFIGURATION MANAGER - MENU ======"<<"\n";
    cout<<"1. Add a Configuration"<<"\n";
    cout<<"2. View a configuration"<<"\n";
    cout<<"3. List all configurations"<<"\n";
    cout<<"4. Exit"<<"\n";
    cout<<"\nEnter a choice: ";
    cin>>choice;

    switch(choice) {

    case 1:
                this->addConfiguration();
    case 2:
//            viewConfiguration();
            break;
    case 3:
//        listAllConfigurations();
        break;

    default:
            cout<<"Invalid Choice\n";
            break;
    }
}

void ConfigManager::addConfiguration() {
    system(clearScreen);
    cout<<"Enter the name of the vehicle: ";
    cin>>this->vehicleName;

    this->addMetadata(vehicleName);
    sleep_until(system_clock::now() + seconds(2));

    configTemplate = this->readFromFile("configTemplate.json");

    system(clearScreen);
    this->vehicle = new Vehicle();
    configTemplate = this->vehicle->addConfiguration(configTemplate);
    sleep_until(system_clock::now() + seconds(2));

    system(clearScreen);
    this->vehicle = new Body();
    configTemplate = this->vehicle->addConfiguration(configTemplate);
    sleep_until(system_clock::now() + seconds(2));

    system(clearScreen);
    this->vehicle = new Drivetrain();
    configTemplate = this->vehicle->addConfiguration(configTemplate);
    sleep_until(system_clock::now() + seconds(2));

    system(clearScreen);
    this->vehicle = new Chasis();
    configTemplate = this->vehicle->addConfiguration(configTemplate);
    sleep_until(system_clock::now() + seconds(2));

    system(clearScreen);
    this->vehicle = new Cabin();
    configTemplate = this->vehicle->addConfiguration(configTemplate);
    sleep_until(system_clock::now() + seconds(2));

    metadata = this->readFromFile(metadataFilename);
    string fileLocation = metadata[vehicleName].get<string>();
    bool configWrite = this->writeToFile(configTemplate,fileLocation);
    if(configWrite) {
        system(clearScreen);
        cout<<"\n*****Configuration written to the JSON file*****\n";
        sleep_until(system_clock::now() + seconds(2));
    }
    else {
        system(clearScreen);
        cout<<"\n-----Configuration could not be written-----\n";
        sleep_until(system_clock::now() + seconds(2));
    }
    this->displayMainMenu();
}


int main() {

    ConfigManager carCofigManager;
    carCofigManager.displayMainMenu();
    return 0;
}
