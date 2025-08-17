#include <stdio.h>

using namespace std;

int g_sum, g_cnt = 0;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &g_sum);
    fclose(stdin);
}

void mySolve(int num, int sum){
    //printf("sum = %d\n", sum);
    if(sum >= 3){
        if(sum == 3){
            g_cnt++;
        }
        return;
    }

    mySolve(1, sum + 1);
    mySolve(2, sum + 2);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
