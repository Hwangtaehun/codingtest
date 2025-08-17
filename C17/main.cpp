#include <stdio.h>
#include <malloc.h>

using namespace std;

int g_buget, g_kind, g_max = 0, *g_data;
bool *g_used;

//solve
int B, n, act[23], res;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_buget, &g_kind);
    B = g_buget;
    n = g_kind;
    g_data = (int *)malloc(sizeof(int) * g_kind);
    g_used = (bool *)malloc(sizeof(bool) * g_kind);

    for(int i = 0; i < g_kind; i++){
        scanf("%d", &g_data[i]);
        act[i+1] = g_data[i];
        g_used[i] = false;
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_max);
    fclose(stdout);
}

void mySolve(int sum){
    //printf("sum = %d\n", sum);
    if(sum > g_buget)
        return;

    if(sum <= g_buget){
        if(sum > g_max){
            g_max = sum;
        }
    }

    for(int i = 0; i < g_kind; i++){
        if(!g_used[i]){
            g_used[i] = true;
            mySolve(sum + g_data[i]);
            g_used[i] = false;
        }
    }
}

void Solve(int i, int sum){
    if(sum > B)
        return;
    printf("%d, %d, %d\n", i, sum, res);

    if(i == n+1){
        if(sum <= B && sum > res)
            res = sum;
        return;
    }

    Solve(i+1, sum+act[i]);
    Solve(i+1, sum);
}

int main()
{
    Input();
    mySolve(0);
    Solve(1,0);
    printf("%d", res);
    Output();
    free(g_data);
    free(g_used);
    return 0;
}
