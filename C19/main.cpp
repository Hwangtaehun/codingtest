#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

using namespace std;
//-1:left 0:nothing 1:right
int g_use[SIZE];
int g_choo[SIZE] = {1, 3, 9, 27, 81, 243, 729};
int g_total[SIZE + 1];
int g_cnt = 0, g_weight;
bool g_end = false;

//solve
int n, scale[8] = {1, 3, 9, 27, 81, 243, 729}, chk[8], End;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_weight);
    n = g_weight;
    fclose(stdin);
}

void Solve(int n, int sum)
{
    if(End)
        return;

    if(sum == n){
        for(int c = 2; c > 0; c--){
            for(int i = 0; i < 7; i++){
                if(chk[i] == c)
                    printf("%d ", scale[i]);
            }
            if(c == 2)
                printf("0 ");
        }
        End = 1;
    }

    for(int i = 0; i < 7; i++){
        if(chk[i] == 0){
            chk[i] = 1;
            Solve(n, sum + scale[i]);
            chk[i] = 2;
            Solve(n + scale[i] , sum);
            chk[i] = 0;
        }
    }
}

void mySolve(int left, int right){
    if(g_end){
        return;
    }

    if(left == right){
        g_total[g_cnt++] = g_weight;

        for(int i = 0; i < SIZE; i++){
            if(g_use[i] == -1){
                g_total[g_cnt++] = g_choo[i];
            }
        }

        g_total[g_cnt++] = 0;

        for(int i = 0; i < SIZE; i++){
            if(g_use[i] == 1){
                g_total[g_cnt++] = g_choo[i];
            }
        }

        g_end = true;
        return;
    }

    for(int i = 0; i < SIZE; i++){
        if(!g_use[i]){
            g_use[i] = -1;
            mySolve(left + g_choo[i], right);
            g_use[i] = 1;
            mySolve(left, right + g_choo[i]);
            g_use[i] = 0;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_cnt; i++){
        printf("%d ", g_total[i]);
    }
    fclose(stdout);
}

int main()
{
    Input();
    mySolve(g_weight, 0);
    printf("%d ", n);
    Solve(n, 0);
    Output();
    return 0;
}
