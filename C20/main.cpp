#include <stdio.h>
#include <malloc.h>

using namespace std;
//2:X, 1:use, 0:O
int g_n, g_m, g_cnt = 0, **g_data;

void Input()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_n, &g_m);
    fclose(stdin);

    g_data = (int **)malloc((g_n + 1) * sizeof(int *));

    for(int i = 0; i <= g_n; i++){
        g_data[i]= (int *)malloc((g_m + 1) * sizeof(int *));
    }

    for(int i = 0; i <= g_n; i++){
        for(int j = 0; j <= g_m; j++){
            g_data[i][j] = 2;
        }
    }

    for(int i = 0; i <= g_n; i++){
        for(int j = 0; j <= g_m; j++){
            if(j <= i){
                g_data[i][j] = 0;
            }
        }
    }

    g_data[g_n][g_m] = 0;
}

void Output()
{
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

void Print(){
    for(int i = 0; i <= g_n; i++){
        for(int j = 0; j <= g_m; j++){
            printf("%d ", g_data[i][j]);
        }
        printf("\n");
    }
}

void mySolve(int col, int row){
    //printf("%d %d\n", col, row);

    if(col == g_n && row == g_m){
        g_cnt++;
        return;
    }

    if(col >= g_n + 1 || row >= g_m + 1 || g_data[col][row] == 2){
        return;
    }

    mySolve(col + 1, row);
    mySolve(col, row + 1);
}

int main()
{
    Input();
    //Print();
    mySolve(0, 0);
    Output();
    return 0;
}
