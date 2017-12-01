#include "JSONHandler.h"

JSONHandler::JSONHandler(string templateFile) {
    inFile.open(templateFile);
    if(inFile) {
        inFile>>this->configTemplate;
        inFile.close();
    } else {
        cout<<"can't open file";
    }
}

json JSONHandler::readFromFile(string filename)
{
    inFile.open(filename);
    if(inFile) {
        inFile>>this->jsonData;
    } else {
        cout<<"can't open file";
    }
    return this->jsonData;
}


void JSONHandler::writeToFile(json jsonData,string filename)
{
    outFile.open(filename);
    if(outFile) {
            outFile<<setw(4)<<jsonData<<endl;
    } else {
        cout<<"can't open output file";
    }
}

json JSONHandler::mapToJSON(jsonMap mapData)
{
    for(auto i : mapData)
        jsonData[i.first]=i.second;

    return jsonData;
}

JSONHandler::~JSONHandler()
{
    inFile.close();
    outFile.close();
}
