#include <stdio.h>
#define SIZE 7

using namespace std;
//-1:left 0:nothing 1:right
int g_use[SIZE];
int g_choo[SIZE] = {1, 3, 9, 27, 81, 243, 729};
int g_total[SIZE + 1];
int g_tcnt, g_weight;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_weight);
    fclose(stdin);
}

void mySolve(int left, int right){
    printf("%d <=> %d\n", right, left);

    if(left == right){
        g_total[g_tcnt++] = g_weight;

        for(int i = 0; i < SIZE; i++){
            if(g_use[i] == -1){
                g_total[g_tcnt++] = g_choo[i];
            }
        }

        g_total[g_tcnt++] = 0;

        for(int i = 0; i < SIZE; i++){
            if(g_use[i] == 1){
                g_total[g_tcnt++] = g_choo[i];
            }
        }

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
    //freopen("output.txt", "w", stdout);
    for(int i = 0; i < g_tcnt; i++){
        printf("%d ", g_total[i]);
    }
    //fclose(stdout);
}

int main()
{
    Input();
    mySolve(g_weight, 0);
    Output();
    return 0;
}
