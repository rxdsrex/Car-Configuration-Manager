#include "JSONHandler.h"

JSONHandler::JSONHandler(string templateFile) {
    inFile.open(templateFile);
    if(inFile) {
        inFile>>this->handlerJSON;
        inFile.close();
    } else {
        cout<<"Cannot open file";
    }
    inFile.close();
}

JSONHandler::JSONHandler() {

}

json JSONHandler::readFromFile(string filename) {
    this->jsonData.clear();
    inFile.open(filename);
    if(inFile) {
        inFile>>this->jsonData;
    } else {
        cout<<"Cannot open input file";
    }
    inFile.close();
    return this->jsonData;
}


bool JSONHandler::writeToFile(json jsonData,string fileLocation) {
    outFile.open(fileLocation);
    if(outFile) {
        outFile<<setw(4)<<jsonData<<endl;
        return true;
    }
    else {
        return false;
    }
    outFile.close();
}

json JSONHandler::mapToJSON(jsonMap mapData) {
    for(auto i : mapData)
        jsonData[i.first]=i.second;
    return jsonData;
}

void JSONHandler::addMetadata(string carname) {
    string folder = "configurations/";
    string filelocation =  folder.append(carname + ".json");
    ifstream metafile;
    metafile.open("metadata.json");
    metafile >> this->metadata;
    this->metadata.emplace(carname , filelocation);
    metafile.close();

    ofstream configFile;
    configFile.open(filelocation);
    configFile << "{ }" << endl;
    configFile.close();

    ofstream joutFile;
    joutFile.open("metadata.json");
    joutFile << setw(4) << this->metadata << endl;
    joutFile.close();

    cout<<"\n\nMetadata added and configuration file initialized.\n\n";
}

JSONHandler::~JSONHandler()
{
    inFile.close();
    outFile.close();
}
