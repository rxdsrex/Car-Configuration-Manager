#include "MyHeader.h"

int main()
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
