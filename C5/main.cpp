#include <stdio.h>

using namespace std;
int g_N, g_M, g_W, g_H, g_Max;
int **g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_N, &g_M);
    scanf("%d %d", &g_W, &g_H);

    g_data = new int*[g_N];

    for(int i = 0; i < g_N; i++){
        g_data[i] = new int[g_M];
    }

    for(int i = 0; i < g_N; i++){
        for(int j = 0; j < g_M; j++){
            scanf("%d", &g_data[i][j]);
        }
    }

    fclose(stdin);
}

void mySolve(){
    int m_Max;
    for(int i = 0; i <= g_N - g_W;  i++){
        for(int j = 0; j < g_M - g_H; j++){
            m_Max = 0;
            for(int k = i; k < i + g_W; k++){
                for(int l = j; l < j + g_H; l++){
                    m_Max += g_data[k][l];
                }
            }
            if(g_Max < m_Max){
                g_Max = m_Max;
            }
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_Max);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
