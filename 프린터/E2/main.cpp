#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> g_result;
int g_size;

//solve
#define MAX 10000
char str[MAX + 1];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_size);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        cout << g_result[i] << endl;
    }
    fclose(stdout);
}

void mySolve(){
    int m_cnt = 1;
    while(m_cnt <= g_size){
        vector<char> m_char;

        for(int i = 0; i < m_cnt; i++){
            m_char.push_back('*');
        }

        string m_str(m_char.begin(), m_char.end());
        g_result.push_back(m_str);
        m_cnt++;
    }
}

void Solve1(int n){
    if(n == 1){
        putchar('*');
        putchar('\n');
    }else{
        Solve1(n - 1);
        for(int i = 0; i < n; i++){
            putchar('*');
        }
        putchar('\n');
    }
}

void Solve2(int n){
    if(n > 0){
        Solve2(n - 1);
        for(int i = 0; i < n; i++){
            putchar('*');
        }
        putchar('\n');
    }
}

void Solve3(int n){
    if(n > 0){
        Solve3(n - 1);
        str[n] = '*';
        printf("%s\n", str + 1);
    }
}

int main()
{
    int n;
    Input();
    n = g_size;
    Solve1(n);
    Solve2(n);
    Solve3(n);
    mySolve();
    Output();
    return 0;
}
