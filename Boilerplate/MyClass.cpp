#include "MyHeader.h"

int main()
{
    int choice;
    while(1){
        cout<<"1. From json object to c++ data types\n";
        cout<<"2. From json file to map (STL)\n";
        cout<<"3. From json object to std::output\n";
        cout<<"4. From json object to file\n";
        cout<<"5. Append json to an array\n";
        cout<<"Enter choice: ";
        cin>>choice;
        json j_object;
        j_object = {{"one", 1}, {"two", 2}};
        switch(choice){
        case 1:
            {
                // create a JSON value with different types
                json json_types =
                    {
                        {"boolean", true},
                        {
                            "number", {
                                {"integer", 42},
                                {"floating-point", 17.23}
                            }
                        },
                        {"string", "Hello, world!"},
                        {"array", {1, 2, 3, 4, 5}},
                        {"null", nullptr}
                    };

                // use explicit conversions
                auto v1 = json_types["boolean"].get<bool>();
                auto v2 = json_types["number"]["integer"].get<int>();
                auto v3 = json_types["number"]["integer"].get<short>();
                auto v4 = json_types["number"]["floating-point"].get<float>();
                auto v5 = json_types["number"]["floating-point"].get<int>();
                auto v6 = json_types["string"].get<string>();
                auto v7 = json_types["array"].get<vector<short>>();
                auto v8 = json_types.get<unordered_map<string, json>>();

                // print the conversion results
                cout << v1 << '\n';
                cout << v2 << ' ' << v3 << '\n';
                cout << v4 << ' ' << v5 << '\n';
                cout << v6 << '\n';
                for(auto i : v7)
                    cout << i << ' ';
                cout << "\n\n";
                for(auto i : v8)
                    cout << i.first << ": " << i.second << '\n';
            }
            break;

        case 2:
            {
                system("cls");      //replace with system("clear") in linux
                // read a JSON file
                ifstream infile;
                infile.open("file.json");
                json filej;
                infile >> filej;
                auto filev = filej.get<unordered_map<string, json>>();
                for(auto i : filev)
                    cout << i.first << ": " << i.second << '\n';
            }
            break;
        case 3:
            {
                // create a JSON value with different types
                json json_types =
                    {
                        {"boolean", true},
                        {
                            "number", {
                                {"integer", 42},
                                {"floating-point", 17.23}
                            }
                        },
                        {"string", "Hello, world!"},
                        {"array", {1, 2, 3, 4, 5}},
                        {"null", nullptr}
                    };
                    cout << setw(4) << json_types << endl;
            }
            break;
        case 4:
            {
                // create a JSON value with different types
                json json_types =
                    {
                        {"boolean", true},
                        {
                            "number", {
                                {"integer", 42},
                                {"floating-point", 17.23}
                            }
                        },
                        {"string", "Hello, world!"},
                        {"array", {1, 2, 3, 4, 5}},
                        {"null", nullptr}
                    };
                    ofstream open("pretty.json");
                    open << setw(4) << json_types << std::endl;
            }
            break;
        case 5:
            {
                json null;
                json null1;
                string folder = "configurations/";
                string file = "metadata";
                string filelocation =  folder.append(file + ".json");
                ifstream metafile;
                metafile.open(filelocation);
                metafile >> null;
                auto now = chrono::system_clock::now();
                time_t toTime = std::chrono::system_clock::to_time_t(now);
				string time = (string)ctime(&toTime);


                //json car = {"carname": {"name": "carname","location": filelocation, "Last modified": time}};
                null.emplace(j_object);
                metafile.close();

                cout << null << endl;
				
				// currentConfiguration = vehicleAttributes[choice - 1];
				// if(currentConfiguration == "Body")
				// 	choice = 1;
				// if(currentConfiguration == "Cabin")
				// 	choice = 2;
				// if(currentConfiguration == "Chassis")
				// 	choice = 3;
				// if(currentConfiguration == "Drivetrain")
				// 	choice = 4;
				// if(currentConfiguration == "Vehicle")
				// 	choice = 5;

                // ofstream jout;
                // jout.open(filelocation);
                // jout << setw(4) << null << std::endl;
                // jout.close();

                // metafile.open(filelocation);
                // metafile >> null1;
                // null1.emplace("CarName2" , "filename2");
                // null1.emplace("CarName3" , "filename3");
                // metafile.close();

                // cout << null1 << endl;

                // jout.open(filelocation);
                // jout << setw(4) << null1 << std::endl;
                // jout.close();
            }
            break;
        default:
            break;
        }
    }
}
