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
    set<int> s = {1, 3, 2, 1, 5};
    s.insert(4);
    Print(s);
    s.erase(2);
    Print(s);

    auto it = s.find(4);
    if(it != s.end()){
        s.erase(it);
    }
    Print(s);

    return 0;
}
