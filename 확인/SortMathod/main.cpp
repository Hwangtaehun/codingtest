#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>

Print(T v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v ={4, 2, 5, 3, 1};
    sort(v.begin(), v.end());
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    sort(v.rbegin(), v.rend());
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
