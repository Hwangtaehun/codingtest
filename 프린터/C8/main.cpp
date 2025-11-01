#include <stdio.h>

using namespace std;

int g_start, g_goal, g_min = 0x7FFFFFFF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_start, &g_goal);
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int tem, int cnt){
    //important
    if(cnt > g_min){
        return;
    }
    //

    if(tem == g_goal){
        if(cnt < g_min){
            g_min = cnt;
        }
        return;
    }
    else if(tem < g_goal){
        mySolve(tem + 1, cnt + 1);
        mySolve(tem + 5, cnt + 1);
        mySolve(tem + 10, cnt + 1);
    }else{
        mySolve(tem - 1, cnt + 1);
        mySolve(tem - 5, cnt + 1);
        mySolve(tem - 10, cnt + 1);
    }
}

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
