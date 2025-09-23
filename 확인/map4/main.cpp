#include <iostream>
#include <map>

using namespace std;

template <typename T>

void Print(T Map){
    for(const auto &pair : Map) {
        cout << pair.first << ": " << pair.second << " ";
    }
    cout << endl;
}

int main()
{
    map<int, string> myMap;
    myMap.insert(make_pair(2, "Banana"));
    myMap[3]="Cherry";
    myMap.insert({1, "Apple"});

    Print(myMap);

    myMap.erase(2);

    Print(myMap);

    auto it = myMap.find(3);
    if(it != myMap.end()) {
        myMap.erase(it);
    }

    Print(myMap);

    return 0;
}
