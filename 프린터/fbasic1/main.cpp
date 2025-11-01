#include <iostream>

using namespace std;

int DT[100001];

int Fibonacci(int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }else if(n < 0){
        return -1;
    }else{
        return Fibonacci(n - 2) + Fibonacci(n - 1);
    }
}

int f1(int n){
    if(n <= 2){
        return 1;
    }
    return f1(n - 1) + f1(n - 2);
}

int f2(int n){
    if(n <= 2){
        return 1;
    }
    else if(!DT[n]){
        DT[n] = f2(n-1) + f2(n-2);
    }
    return DT[n];
}

int main()
{
    int n;
    cin >> n;
    cout << Fibonacci(n) << endl;
    cout << f1(n) << endl;
    cout << f2(n) << endl;
    return 0;
}
