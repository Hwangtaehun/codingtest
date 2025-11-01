#include <stdio.h>
#include <malloc.h>

using namespace std;
//2:X, 1:use, 0:O
int g_n, g_m, g_cnt = 0, **g_data;

//solve
int H, W, wayCnt;
int data[101][101];

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
    H = g_n, W = g_m;
}

void Output()
{
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

void ArrayPrn(){
    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            printf("%d ", data[i][j]);
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

void Solve1(int h, int w)
{
    if(h > H || w > W)
        return;

    if(h == H && w == W){
        wayCnt++;
        return;
    }

    Solve1(h+1, w);

    if((double) H/W <= (double)h/(w+1))
    {
        Solve1(h, w+1);
    }
}

void Solve2(){
    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 && j == 0)
                data[i][j] = 1;
            else{
                if(i * W >= j * H && j > 0)
                    data[i][j] += data[i][j - 1];
                if((i - 1) * W >= j * H && i > 0)
                    data[i][j] += data[i - 1][j];
            }
        }
    }
}

int main()
{
    Input();
    mySolve(0, 0);
    Solve1(0, 0);
    printf("%d\n", wayCnt);
    Solve2();
    ArrayPrn();
    printf("%d\n", data[H][W]);
    Output();
    return 0;
}
