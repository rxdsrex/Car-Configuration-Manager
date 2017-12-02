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

JSONHandler::JSONHandler() {

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

    cout<<"Metadata added and configuration file initialized.";
}

JSONHandler::~JSONHandler()
{
    inFile.close();
    outFile.close();
}
