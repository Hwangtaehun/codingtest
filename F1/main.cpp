#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

vector<int> g_data;

//Solve
int n, DT[50001];

void Input(){
    string m_str;

    ifstream in("input.txt");
    in >> m_str;

    for(int i = 0; i < m_str.size(); i++){
        char c = m_str[i];
        int x = c - '0';
        g_data.push_back(x);
    }

    stringstream ss(m_str);
    ss >> n;
}

void Output(){
    ofstream out("output.txt");

    for(int i = g_data.size() - 1; i >= 0; i--){
        if(g_data[i] != 0){
            out << g_data[i];
        }
    }
}

int reverseNumber(int n){
    int res = 0;
    while(n > 0){
        res = res * 10 + (n % 10);
        n /= 10;
    }
    return res;
}

void f1(){
    for(int i = 1; i <= n; i++){
        if(i < 10){
            DT[i] = i;
        }else{
            DT[i] = reverseNumber(i);
        }
    }
    printf("%d\n", DT[n]);
}

int f2(int n){
    if(n < 10)
        return n;

    if(!DT[n]){
        DT[n] = reverseNumber(n);
    }

    return DT[n];
}

int main()
{
    Input();
    f1();
    printf("%d\n", f2(n));
    Output();
    return 0;
}
