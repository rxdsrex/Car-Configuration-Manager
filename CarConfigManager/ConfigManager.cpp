#include "JSONHandler.h"

class ConfigManager {

private:
    string engine
public:

};

class InternalConfig:public ConfigManager {

};

class ExternalConfig:public ConfigManager {

};

int main(int argc, char* argv[]){

    ConfigManager myConfigManager;
    myConfigManager.handler = new JSONHandler();
    myConfigManager.jsonConfig = myConfigManager.handler->readFromFile("../internal.json");
    myConfigManager.handler->writeToFile(myConfigManager.jsonConfig,"testfile.json");
    return 0;
}
