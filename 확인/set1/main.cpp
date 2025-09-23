#include <iostream>
#include <set>

using namespace std;

void Print(set<int> v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    set<int> s1;
    set<int> s2 = {3, 1, 3, 2, 5};
    set<int> s3(s2);

    Print(s2);
    Print(s3);

    return 0;
}
