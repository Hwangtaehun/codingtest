#include <iostream>
#include <vector>

using namespace std;

void Print(vector<int> v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {2, 3, 4, 5};
    Print(v);

    v.push_back(6);
    Print(v);

    v.pop_back();
    Print(v);

    v.insert(v.begin(), 1);
    Print(v);

    v.erase(v.begin());
    Print(v);

    v.insert(v.begin() + 2, 1);
    Print(v);

    v.erase(v.begin() + 2);
    Print(v);

    return 0;
}
