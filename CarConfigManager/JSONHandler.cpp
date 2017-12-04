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
        outFile.close();
        return true;
    }
    else {
        outFile.close();
        return false;
    }
}

void JSONHandler::addMetadata(string carname) {
    string folder = "configurations/";
    string filelocation =  folder.append(carname + ".json");
    ifstream checkfile("metadata.json");
    if(!checkfile){
        checkfile.close();
        ofstream metaoutfile;
        metaoutfile.open("metadata.json");
        metaoutfile << "{\"CarList\":[]}" << endl;
        metaoutfile.close();
    }
    ifstream metafile("metadata.json");
    metafile >> this->metadata;
    auto now = chrono::system_clock::now();
    time_t toTime = std::chrono::system_clock::to_time_t(now);
	string time = (string)ctime(&toTime);
	json attributes;
	attributes.emplace("Location",filelocation);
    attributes.emplace("Last modified",time);
	this->metadata.emplace(carname,attributes);
    this->metadata["CarList"].emplace_back(carname);
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

bool JSONHandler::editToFile(json data,string fileLocation,string objectName){
    this->jsonData.clear();
    inFile.open(fileLocation);
    if(inFile) {
        inFile>>this->jsonData;
    } else {
        cout<<"Cannot open input file";
    }
    inFile.close();

    this->jsonData.erase(this->jsonData.find(objectName));
    this->jsonData.emplace(objectName,data);

    outFile.open(fileLocation);
    if(outFile) {
        outFile<<setw(4)<<this->jsonData<<endl;
        outFile.close();
        return true;
    }
    else {
        outFile.close();
        return false;
    }
}

JSONHandler::~JSONHandler()
{
    inFile.close();
    outFile.close();
}
