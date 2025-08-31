#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<int> g_data;
int g_result;

//solve
bool bFirst = true;

void Input(){
    string m_str;

    freopen("input.txt", "r", stdin);
    cin >> m_str;
    fclose(stdin);

    for(size_t i = 0; i < m_str.size(); i++) {
        g_data.push_back((int)(m_str[i] - '0'));
    }
}

void Print(){
    for(int i = 0; i < g_data.size(); i++){
        printf("%d", g_data[i]);
    }
    printf("\n");
}

void Output(){
    freopen("output.txt","w", stdout);
    printf("%d", g_result);
    fclose(stdout);
}

void mySolve(){
    int num = 0;
    for(int i = g_data.size() - 1; i >= 0; i--){
        num = num * 10 + g_data[i];
    }

    g_result = num;
}

void Solve1(int n){
    if(n == 0)
        return;
    printf("%d", n%10);
    Solve1(n/10);
}

void Solve2(int n){
    if(n == 0)
        return;
    if(!bFirst || (n%10) != 0)
    {
        printf("%d", n%10);
        bFirst = 0;
    }
    Solve2(n / 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    Solve1(n);
    printf("\n");
    Solve2(n);

    Input();
    mySolve();
    Output();
    return 0;
}
