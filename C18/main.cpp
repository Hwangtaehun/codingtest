#include <stdio.h>
#include <malloc.h>
#define SIZE 2

using namespace std;

int g_n, g_w, g_max = 0, **g_data;
bool *g_use;

void Input()
{
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_n, &g_w);

    g_data = (int **)malloc(g_n * sizeof(int *));
    g_use = (bool *)malloc(g_n * sizeof(bool *));

    for(int i = 0; i < g_n; i++){
        g_data[i] = (int *)malloc((SIZE)* sizeof(int));
    }

    for(int i = 0; i < g_n; i++){
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
    }

    fclose(stdin);

    for(int i = 0; i < g_n; i++){
        g_use[i] = false;
    }
}

void Output()
{
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void Print(){
    for(int i = 0; i < g_n; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
}

bool Check(){
    for(int i = 0; i < g_n; i++){
        if(!g_use[i]){
            return false;
        }
    }
    return true;
}

void mySolve(int weight, int value){
    //printf("%d %d\n", weight, value);

    if(Check()){
        return;
    }

    if(weight >= g_w){
        if(weight == g_w){
            if(value > g_max){
                g_max = value;
            }
        }
        return;
    }

    for(int i = 0; i < g_n; i++){
        if(!g_use[i]){
            g_use[i] = true;
            mySolve(weight + g_data[i][0], value + g_data[i][1]);
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
