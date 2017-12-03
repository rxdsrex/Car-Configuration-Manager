#include "json.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
using json = nlohmann::json;

int main() {
                json null;
                string folder = "configurations/";
                string file = "metadata";
                string filelocation =  folder.append(file + ".json");
                ifstream metafile(filelocation);
                if(!metafile)
                    cout<<"false\n";
                metafile >> null;
                auto now = chrono::system_clock::now();
                time_t toTime = std::chrono::system_clock::to_time_t(now);
				string time = (string)ctime(&toTime);
				//json j_object = {{"one", 1}, {"two", 2}};
				json attributes;
				attributes.emplace("name","carname");
				attributes.emplace("location",filelocation);
				attributes.emplace("Last modified",time);
                null.emplace("carname",attributes);
                null["carlist"].emplace_back(1);
                null["carlist"].emplace_back(2);
                //null = {{"carname",attributes}};
                metafile.close();

                cout << setw(4) << null << endl;
}
