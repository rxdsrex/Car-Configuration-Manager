#include "json.hpp"
using json = nlohmann::json;
using namespace std;

int main() {

    json hvac;
    json internal;
    hvac["cabin temperature"] = 20;
    hvac["solar load"] = 35;
    hvac["heat load"] = 440;
    hvac["number of passengers"] = 4;
    hvac["other loads"] = {"lighting","electrical equipment","appliances"};
    internal["internal"] = hvac;
    cout << setw(4) << internal  << endl;

//    // create an empty structure (null)
//json j;
//
//// add a number that is stored as double (note the implicit conversion of j to an object)
//j["pi"] = 3.141;
//
//// add a Boolean that is stored as bool
//j["happy"] = true;
//
//// add a string that is stored as std::string
//j["name"] = "Niels";
//
//// add another null object by passing nullptr
//j["nothing"] = nullptr;
//
//// add an object inside the object
//j["answer"]["everything"] = 42;
//
//// add an array that is stored as std::vector (using an initializer list)
//j["list"] = { 1, 0, 2 };
//
//// add another object (using an initializer list of pairs)
//j["object"] = { {"currency", "USD"}, {"value", 42.99} };


    return 0;
}
