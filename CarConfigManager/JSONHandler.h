#ifndef JSONHANDLER_H_INCLUDED
#define JSONHANDLER_H_INCLUDED

#include "json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

using json = nlohmann::json;

class JSONHandler{
private:
    json j;
    ifstream infile;
    ofstream outfile;
public:
    JSONHandler();
    explicit JSONHandler(const JSONHandler&);
    ~JSONHandler();
    json readFromFile(string);
    void writeToFile(json,string);
    json mapToJSON(unordered_map<string, json>);
};


#endif // JSONHANDLER_H_INCLUDED
