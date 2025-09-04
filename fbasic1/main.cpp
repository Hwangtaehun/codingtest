#include <iostream>

using namespace std;

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

int main()
{
    int m_n;
    cin >> m_n;
    cout << Fibonacci(m_n) << endl;
    return 0;
}
