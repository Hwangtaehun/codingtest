#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string , int> myMap = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};

    for(auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    auto result = myMap.find("banana");

    if(result != myMap.end()) {
        cout << "Found: " << result->first << " -> " << result->second << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
