#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define KIND 2

using namespace std;

int g_size, g_sum, g_min = 0x7FFFFFFF;
int **g_data;
bool *g_use;

//모범답안
int M,n,i,m[101],c[101];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_sum);

    g_use = (bool *)malloc(sizeof(bool) * g_size);
    g_data = (int **)malloc(KIND * sizeof(int *));

    for(int i = 0; i < KIND; i++){
        g_data[i] = (int *)malloc(g_size * sizeof(int));
    }

    for(int i = 0; i < KIND; i++){
        for(int j = 0; j < g_size; j++){
            scanf("%d", &g_data[i][j]);
        }
    }
    fclose(stdin);

    for(int i = 0; i < g_size; i++){
        g_use[i] = false;
    }

    n = g_size;
    M = g_sum;

    memcpy(m + 1, g_data[0], n*sizeof(int));
    memcpy(c + 1, g_data[1], n*sizeof(int));
}

void Print(){
    printf("g_size = %d, g_sum = %d\n", g_size, g_sum);
    for(int i = 0; i < g_size; i++){
        printf("%d ", g_use[i]);
    }
    printf("\n");

    for(int i = 0; i < KIND; i++){
        for(int j = 0; j < g_size; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
}

void Print(int m[], int c[]){
    for(int i = 1; i <= n; i++){
        printf("%d ", m[i]);
    }
    printf("\n");

    for(int i = 1; i <= n; i++){
        printf("%d ", c[i]);
    }
    printf("\n");
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int mem, int cost){
    if(mem >= g_sum){
        if(cost < g_min){
            g_min = cost;
        }
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(!g_use[i]){
            g_use[i] = true;
            mem += g_data[0][i];
            cost += g_data[1][i];
            mySolve(mem, cost);
            g_use[i] = false;
        }
    }
}

int Min(int a, int b){
    return a < b ? a : b;
}

int Solve(int i, int r){
    if(r <= 0)
        return 0;
    //printf("%d,%d \n", i, r);

    if(i==0)
    {
        return 99999;
    }else
        return Min(Solve(i-1, r), Solve(i-1, r - m[i]) + c[i]);
}

int main()
{
    Input();
    Print(m, c);
    mySolve(0, 0);
    printf("%d\n", Solve(n, M));
    Output();
    return 0;
}
