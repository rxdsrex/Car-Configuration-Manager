#include "JSONHandler.h"

class ConfigManager {
private:
    JSONHandler handler;
    json jsonConfig;
};

class InternalConfig:public ConfigManager {

};

class ExternalConfig:public ConfigManager {

};

int main(int argc, char* argv[]){

    return 0;
}
