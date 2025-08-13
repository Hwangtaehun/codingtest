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

void mySolve(){
    for(int i = 0; i <= g_n - g_w; i++){
        int m_cost = 0;

        for(int j = 0; j < g_w; j++){
            m_cost += g_data[i + j];
        }

        //printf("m_cost = %d\n", m_cost);
        if(m_cost > g_cost){
            g_cost = m_cost;
        }
    }
}

void Solve(){
    int tot, maxTot = 0;
    for(int i = 0; i <= g_n - g_w; i++){
        tot = 0;
        for(int j = i;  j < i + g_w; j++){
            tot += g_data[j];
            //printf("%d ", j);
        }
        //printf("\n");
        if( tot > maxTot)
            maxTot = tot;
    }
    printf("%d\n", maxTot);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cost);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve();
    Solve();
    Output();
    delete[] g_data;
    return 0;
}
