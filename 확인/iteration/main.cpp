#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    for(int num : vec){
        cout << num << " ";
    }
    cout << endl;

    map<string, int> fruitMap = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};
    for(const auto& pair : fruitMap) {
        cout << pair.first << " = " << pair.second << " ";
    }
    cout << endl;

    set<string> fruitSet = {"apple", "banana", "cherry"};
    cout << "Set: ";
    for(const auto& fruit : fruitSet) {
        cout << fruit << " ";
    }
    cout << endl;

    return 0;
}
