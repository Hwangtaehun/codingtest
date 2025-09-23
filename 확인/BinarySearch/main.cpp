#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    cout << binary_search(v.begin(), v.end(), 3) << endl;
    cout << binary_search(v.begin(), v.end(), 7) << endl;

    return 0;
}
