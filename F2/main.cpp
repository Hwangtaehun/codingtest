#include <cstdio>

using namespace std;

int g_n, g_r, g_final;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_n, &g_r);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_final);
    fclose(stdout);
}

void mySolve(){
    int m_n = 1, m_r = 1;
    int m_cnt = 0;

    while(m_cnt < g_r){
        m_n *= (g_n - m_cnt);
        m_cnt++;
    }

    for(int i = 1; i <= g_r; i++){
        m_r *= i;
    }

    g_final = m_n / m_r;
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
