#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};

    do{
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }while(next_permutation(v.begin(), v.end()));

    return 0;
}
