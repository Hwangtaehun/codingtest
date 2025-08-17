#include <stdio.h>

using namespace std;

int g_cnt, g_sum = 0;
int *g_data;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &g_cnt);
    g_data = new int[g_cnt];

    for(int i = 0; i < g_cnt; i++){
        scanf("%d", &g_data[i]);
    }

    fclose(stdin);
}

void mySolve(){
    int sum = 0;

    for(int i = 1; i <= g_cnt; i++){
        //printf("-----------------\ni = %d\n------------------\n", i);
        for(int j = 0; j <= g_cnt - i; j++){
            //printf("j = %d\n", j);
            //printf("j+i = %d\n", j+i);
            for(int k = j; k < j+i; k++){
                //printf("%d, ", k);
                sum += g_data[k];
            }
            //printf("\n");
            //printf("sum = %d\n", sum);
            if(sum > g_sum){
                g_sum = sum;
            }
            sum = 0;
        }
    }
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_sum);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve();
    Output();
    return 0;
}
