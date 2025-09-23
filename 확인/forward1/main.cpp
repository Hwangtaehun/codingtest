#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {10, 20, 30, 40, 50};

    for(auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    auto result = find(vec.begin(), vec.end(), 30);
    if(result != vec.end()){
        cout << "Found: " << *result << endl;
    }else{
        cout << "Not Found" << endl;
    }

    return 0;
}
