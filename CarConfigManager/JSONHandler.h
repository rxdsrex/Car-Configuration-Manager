#ifndef JSONHANDLER_H_INCLUDED
#define JSONHANDLER_H_INCLUDED

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <unordered_map>

using namespace std;
using json = nlohmann::json;
typedef unordered_map<string,json> jsonMap;

class JSONHandler{
private:
    json handlerJSON;
    json metadata;
    json jsonData;
    ifstream inFile;
    ofstream outFile;
public:
    JSONHandler();
    JSONHandler(string);
    json readFromFile(string);
    bool writeToFile(json,string);
    void addMetadata(string);
    bool editToFile(json,string,string);
    virtual ~JSONHandler();
};


#endif // JSONHANDLER_H_INCLUDED
