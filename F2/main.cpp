#include <cstdio>

using namespace std;

int g_n, g_r, g_final;

//Solve
int N, K, ans, DT[31][31];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_n, &g_r);
    fclose(stdin);

    N = g_n;
    K = g_r;
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

void solve(int n, int k){
    if(k == K){
        ans++;
        return;
    }

    if(n == N)
        return;

    solve(n + 1, k + 1);
    solve(n + 1, k);
}

int f(int n, int k){
    if(k == K)
        return 1;

    if(n == N)
        return 0;

    if(!DT[n][k])
        DT[n][k] = f(n + 1, k + 1) + f(n + 1, k);

    return DT[n][k];
}

int main()
{
    Input();
    solve(0, 0);
    printf("%d\n", ans);
    printf("%d\n", f(0, 0));
    mySolve();
    Output();
    return 0;
}
