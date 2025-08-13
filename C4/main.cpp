#include <stdio.h>

using namespace std;

int g_n, g_w, g_cost;
int *g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_n);
    scanf("%d", &g_w);
    g_data = new int[g_n];

    for(int i = 0; i < g_n; i++){
        scanf("%d", &g_data[i]);
    }
    fclose(stdin);
}

void Solve(){
    for(int i = 0; i <= g_n - g_w; i++){
        int m_cost = 0;

        for(int j = 0; j < 3; j++){
            m_cost += g_data[i + j];
        }

        printf("m_cost = %d\n", m_cost);
        if(m_cost > g_cost){
            g_cost = m_cost;
        }
    }
}

int main()
{
    Input();
    Solve();
    printf("g_cost = %d\n", g_cost);
    delete[] g_data;
    return 0;
}
