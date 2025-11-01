#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int g_s, g_e, g_dis;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_s, &g_e);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_dis);
    fclose(stdout);
}

int Small(int a, int b){
    return a < b ? a : b;
}

void mySolve(){
    vector<int> m_start, m_end;

    int m_temp = g_s;

    while(m_temp > 0){
        m_start.push_back(m_temp);
        m_temp /= 2;
    }

    m_temp = g_e;

    while(m_temp > 0){
        m_end.push_back(m_temp);
        m_temp /= 2;
    }

    sort(m_start.begin(), m_start.end());
    sort(m_end.begin(), m_end.end());

    int m_sma = Small(m_start.size(), m_end.size());
    int m_pa = 0;

    for(int i = 0; i < m_sma; i++){
        if(m_start[i] == m_end[i]){
            m_pa = m_start[i];
        }
    }

    reverse(m_start.begin(), m_start.end());
    reverse(m_end.begin(), m_end.end());

    for(int i = 0; i < m_start.size(); i++){
        if(m_start[i] == m_pa){
            g_dis += i;
            break;
        }
    }

    for(int i = 0; i < m_end.size(); i++){
        if(m_end[i] == m_pa){
            g_dis += i;
            break;
        }
    }
}

int Solve(int a, int b){
    if(a == b)
        return 0;
    if(b > a)
        return Solve(a, b / 2) + 1;
    if(a > b)
        return Solve(a / 2, b) + 1;
}

int main()
{
    int a, b;
    Input();
    a = g_s;
    b = g_e;
    mySolve();
    printf("%d\n", Solve(a, b));
    Output();
    return 0;
}
