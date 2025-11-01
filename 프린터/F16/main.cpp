#include <cstdio>
#include <vector>
#define SIZE 3

using namespace std;

int g_size, g_dis = 0x0FFFFFFF, g_min = 0x0FFFFFFF;
vector<bool> g_used;
vector<int> g_data, g_result;

//solve
#include <memory.h>

int n, W, G[21], A, B, C;
bool DT[21][2001][2001];

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &g_size);
    g_data.resize(g_size);
    g_used.resize(g_size);
    for(int i = 0; i < g_size; i++){
        scanf("%d", G + i);
        g_data[i] = G[i];
        g_used[i] = false;
        W += G[i];
    }

    fclose(stdin);

    g_result.resize(SIZE);
    n = g_size;
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_result.size(); i++){
        printf("%d ", g_result[i]);
    }
    fclose(stdout);
}

void Switch(int *a, int *b, int *c){
    int temp;

    if(*a < *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if(*b < *c){
        temp = *b;
        *b = *c;
        *c = temp;
    }

    if(*a < *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void mySolve(int i, int a, int b, int c){
    if(i == g_size){
        Switch(&a, &b, &c);

        if((a - c) <= g_dis){
            if(a <= g_min){
                g_min = a;
                g_dis = a - c;
                g_result[0] = a;
                g_result[1] = b;
                g_result[2] = c;
            }
        }
        return;
    }

    mySolve(i + 1, a + g_data[i], b, c);
    mySolve(i + 1, a, b + g_data[i], c);
    mySolve(i + 1, a, b, c + g_data[i]);
}

void Solve1(){
    int ans = 0x0FFFFFFF;
    memset(DT, 0, sizeof(DT));
    DT[0][0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int a = 0; a <= 2000; a++){
            for(int b = 0; b <= 2000; b++){
                DT[i][a][b] = (DT[i - 1][a][b] || (a - G[i] < 0 ? false : DT[i - 1][a - G[i]][b]) || (b - G[i] < 0 ? false : DT[i - 1][a][b - G[i]]));
            }
        }
    }

    for(int a = 0; a <= 2000; a++){
        for(int b = 0; b <= 2000; b++){
            if(DT[n][a][b]){
                if(W - (a + b) >= a && a >= b && W - (a + b) - b <= ans){
                    ans = W - (a + b) - b;
                    A = W - (a + b);
                    B = a;
                    C = b;
                }
            }
        }
    }

    printf("%d %d %d\n", A, B, C);
}

void Solve2(){
    int ans = 0x0FFFFFFF;
    memset(DT, 0, sizeof(DT));
    DT[0][0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int a = 0; a <= 667; a++){
            for(int b = 0; b <= 667; b++){
                DT[i][a][b] = (DT[i - 1][a][b] || (a - G[i] < 0 ? false : DT[i - 1][a - G[i]][b]) || (b - G[i] < 0 ? false: DT[i -1][a][b - G[i]]));
            }
        }
    }

    for(int a = 0; a <= 667; a++){
        for(int b = 0; b <= 667; b++){
            if(DT[n][a][b]){
                if(W - (a + b) >= a && a >= b && W - (a + b) - b <= ans){
                    ans = W - (a + b) - b;
                    A = W - (a + b);
                    B = a;
                    C = b;
                }
            }
        }
    }

    printf("%d %d %d\n", A, B, C);
}

void Solve3(){
    int ans = 0x0FFFFFFF;
    memset(DT, 0, sizeof(DT));
    DT[0][0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int a = 0; a <= 667; a++){
            for(int b = 0; b <= 667; b++){
                DT[i % 2][a][b] = (DT[(i - 1) % 2][a][b] || (a - G[i] < 0 ? false: DT[(i-1) % 2][a - G[i]][b]) || (b - G[i] < 0 ? false: DT[(i-1)%2][a][b - G[i]]));
            }
        }
    }

    for(int a = 0; a <= 667; a++){
        for(int b = 0; b <= 667; b++){
            if(DT[n%2][a][b]){
                if(W - (a + b) >= a && a >= b && W - (a + b) - b <= ans){
                    ans = W - (a + b) - b;
                    A = W - (a + b);
                    B = a;
                    C = b;
                }
            }
        }
    }

    printf("%d %d %d\n", A, B, C);
}

int main()
{
    Input();
    Solve1();
    Solve2();
    Solve3();
    mySolve(0, 0, 0, 0);
    Output();
    return 0;
}
