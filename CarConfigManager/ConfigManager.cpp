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
        break;
    case 2:
        this->viewConfiguration();
        break;
    case 3:
        //this->listAllConfigurations();
        break;
    default:
        cout<<"Invalid Choice\n";
        break;
    }
}

void ConfigManager::addConfiguration() {
    system(clearScreen);
    cout<<"====== VEHICLE CONFIGURATION MANAGER - Add Configuration ======"<<"\n";
    cout<<"\nEnter the name of the vehicle: ";
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
    string fileLocation = metadata[vehicleName]["Location"].get<string>();
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

void ConfigManager::viewConfiguration(){
    ifstream checkfile("metadata.json");
    if(!checkfile){
        cout<<"No Vehicle configuration present.";
        sleep_until(system_clock::now() + seconds(2));
        this->displayMainMenu();
    }
    int i = 1;
    unsigned int choice;
    string currentConfiguration;
    string currentVehicleName;
    string vehicleFileLocation;
    json vehicleAttributes;
    system(clearScreen);
    cout<<"====== VEHICLE CONFIGURATION MANAGER - View Configuration ======"<<"\n";
    cout<<"\nAvailable vehicle configurations:\n";
    metadata.clear();
    metadata = this->readFromFile(metadataFilename);
    json carList = metadata["CarList"];
    for(string carname : carList)
        cout << i++ << ". " << carname << '\n';
    cout << i << ". Back to Main menu\n";
    cout<<"Choose a vehicle: ";
    cin>>choice;
    if(choice > metadata["CarList"].size()) {
        if(choice == metadata["CarList"].size() + 1)
            this->displayMainMenu();
        cout<<"Invalid input";
        sleep_until(system_clock::now() + seconds(1));
        this->viewConfiguration();
    }
    currentVehicleName = carList[choice-1];
    vehicleFileLocation = metadata[currentVehicleName]["Location"].get<string>();
    vehicleConfiguration = this->readFromFile(vehicleFileLocation);
    for (auto it = vehicleConfiguration.begin(); it != vehicleConfiguration.end(); ++it) {
        vehicleAttributes.emplace_back(string(it.key()));
    }
    while(1) {
        system(clearScreen);
        cout << "*****" << currentVehicleName << " configuration*****\n";
        i = 1;
        for(string options : vehicleAttributes){
            cout << i++ << ". " << options << '\n';
        }
        cout << i << ". Back to previous menu.\n";
        cout << "Choose a configuration: ";
        cin>>choice;
        switch(choice) {
            case 1:
            {
                system(clearScreen);
                this->vehicle = new Body();
                json bodyJSON = vehicleConfiguration["Body"];
                this->vehicle->viewConfiguration(bodyJSON);
                sleep_until(system_clock::now() + seconds(5));
            }
                break;
            case 2:
            {
                system(clearScreen);
                this->vehicle = new Cabin();
                json cabinJSON = vehicleConfiguration["Cabin"];
                this->vehicle->viewConfiguration(cabinJSON);
                sleep_until(system_clock::now() + seconds(5));
            }
                break;
            case 3:
            {
                system(clearScreen);
                this->vehicle = new Chasis();
                json chassisJSON = vehicleConfiguration["Chassis"];
                this->vehicle->viewConfiguration(chassisJSON);
                sleep_until(system_clock::now() + seconds(5));
            }
                break;
            case 4:
            {
                system(clearScreen);
                this->vehicle = new Drivetrain();
                json drivetrainJSON = vehicleConfiguration["Drivetrain"];
                this->vehicle->viewConfiguration(drivetrainJSON);
                sleep_until(system_clock::now() + seconds(5));
            }
                break;
            case 5:
            {
                system(clearScreen);
                this->vehicle = new Vehicle();
                json vehicleJSON = vehicleConfiguration["Vehicle"];
                this->vehicle->viewConfiguration(vehicleJSON);
                sleep_until(system_clock::now() + seconds(5));
            }
                break;
            case 6:
                this->viewConfiguration();
            default:
                cout<<"Invalid choice";
                sleep_until(system_clock::now() + seconds(1));
                break;
        }
    }
}

int main() {
    ConfigManager carCofigManager;
    carCofigManager.displayMainMenu();
    return 0;
}
