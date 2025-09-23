#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> v3(4, 3);
    vector<int> v4(v3);

    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    for(auto it = v2.begin(); it != v2.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    for(auto it = v3.begin(); it != v3.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    for(auto it = v4.begin(); it != v4.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
