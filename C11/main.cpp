#include <stdio.h>
#include <malloc.h>
#define KIND 2

using namespace std;

int g_size, g_sum, g_min = 0x7FFFFFFF;
int **g_data;
bool *g_use;

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

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
