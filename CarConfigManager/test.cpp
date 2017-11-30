#include "JSONHandler.h"

int main(int argc, char* argv[]){

    JSONHandler *handler = new JSONHandler();
    json jsonConfig = handler->readFromFile("../internal.json");
    auto jsonToMap = jsonConfig.get<unordered_map<string, json>>();
    cout<<"Writing to json from map";
    json test = handler->mapToJSON(jsonToMap);
    handler->writeToFile(test,"mapToJson.json");
    //cout<<jsonToMap<<endl;
    return 0;
}
