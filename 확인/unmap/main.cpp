#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> myUnorderedMap;

    myUnorderedMap["apple"] = 3;
    myUnorderedMap["banana"] = 1;
    myUnorderedMap["cherry"] = 4;
    myUnorderedMap["date"] = 2;

    for(const auto& pair : myUnorderedMap){
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
