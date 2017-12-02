#ifndef JSONHANDLER_H_INCLUDED
#define JSONHANDLER_H_INCLUDED

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

using json = nlohmann::json;

typedef unordered_map<string,json> jsonMap;

class JSONHandler{
private:
    json configTemplate;
    json metadata;
    json jsonData;
    ifstream inFile;
    ofstream outFile;
public:
    JSONHandler();
    JSONHandler(string);
    json readFromFile(string);
    void writeToFile(json,string);
    json mapToJSON(jsonMap);
    void addMetadata(string);
    virtual ~JSONHandler();
};


#endif // JSONHANDLER_H_INCLUDED
