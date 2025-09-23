#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> myUnorderedSet;

    myUnorderedSet.insert(3);
    myUnorderedSet.insert(1);
    myUnorderedSet.insert(4);
    myUnorderedSet.insert(2);

    for(int num : myUnorderedSet) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
