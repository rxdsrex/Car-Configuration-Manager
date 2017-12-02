#include "ConfigManager.h"

void ConfigManager::displayMainMenu() {
    system("cls");
    cout<<"====== CONFIG MANAGER - MENU ======"<<"\n";
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
    system("cls");
    cout<<"Enter the name of the vehicle: ";
    cin>>this->vehicleName;
    this->addMetadata(vehicleName);

    this->vehicle = new Vehicle();
    this->vehicle->addConfiguration();

    this->vehicle = new Body();
    this->vehicle->addConfiguration();

    this->vehicle = new Cabin();
    this->vehicle->addConfiguration();
}


int main() {

    ConfigManager carCofigManager;
    carCofigManager.displayMainMenu();
    return 0;
}
