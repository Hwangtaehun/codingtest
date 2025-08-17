#include <stdio.h>
#include <malloc.h>

using namespace std;

int *g_data;
int g_sum, g_kind, g_cnt = 0x7FFFFFFF;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_sum, &g_kind);

    g_data = (int *)malloc(g_kind * sizeof(int));

    for(int i = 0; i < g_kind; i++){
        scanf("%d", &g_data[i]);
    }

    fclose(stdin);
}

void mySolve(int sum, int coin, int cnt){
    if(sum >= g_sum || coin == g_kind){
        if(sum == g_sum){
            if(cnt < g_cnt){
                g_cnt = cnt;
            }
        }
        return;
    }

    for(int i = 0; sum + g_data[coin]*i <= g_sum; i++){
         mySolve(sum + g_data[coin]*i, coin + 1, cnt + i);
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve(0, 0, 0);
    Output();
    free(g_data);
    return 0;
}
