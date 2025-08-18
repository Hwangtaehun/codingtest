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

bool Check(){
    for(int i = 0; i < SIZE; i++){
        if(!g_use[i])
            return false;
    }
    return true;
}

void mySolve(int left, int right){
    printf("%d <=> %d\n", right, left);

    if(Check()){
        return;
    }

    if(right == left){
        int cnt = 0;

        g_total[cnt] = g_weight;
        cnt++;

        for(int i = 0; i < SIZE; i++){
            if(g_use[i] == -1){
                g_total[cnt] = g_use[i];
                cnt++;
            }
        }

        g_total[cnt] = 0;
        cnt++;

        for(int i = 0; i < SIZE; i++){
            if(g_use[i] == 1){
                g_total[cnt] = g_use[i];
                cnt++;
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
