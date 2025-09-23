#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    for(auto it = vec.rbegin(); it != vec.rend(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    auto result = find(vec.rbegin(), vec.rend(), 30);

    if(result != vec.rend()) {
        cout << "Found: " << *result << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
