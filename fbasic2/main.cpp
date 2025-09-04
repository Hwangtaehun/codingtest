#include <iostream>

using namespace std;

int D[100], n;

int f1(int k){
    if(k == n + 1)
        return 0;
    return k + f1(k + 1);
}

int f2(int k){
    if(k == n + 1)
        return 0;
    D[k] = k + f2(k + 1);
    return D[k];
}

int main()
{
    cin >> n;

    int r = 0;
    for(int i = 1; i <= n; i++){
        r += i;
    }

    cout << r << endl;
    cout << f1(1) << endl;
    cout << f2(1) << endl;
    return 0;
}
