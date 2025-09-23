#include <iostream>
#include <map>

using namespace std;

template <typename T>

void Print(T Map){
    for(const auto& pair : Map) {
        cout << pair.first << " = " << pair.second << " ";
    }
    cout << endl;
}

int main()
{
    map<string, int> myMap = {{"Apple", 1}, {"Banana", 2}, {"Cherry", 3}};
    Print(myMap);
    myMap["Banana"] = 10;
    Print(myMap);
    return 0;
}
