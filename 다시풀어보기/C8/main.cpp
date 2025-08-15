#include <stdio.h>

using namespace std;

int g_a, g_b, g_cnt = 0x7FFFFFFF;

void Input(){
    freopen("Input.txt", "r", stdin);
    scanf("%d %d", &g_a, &g_b);
    fclose(stdin);
}

void Output(){
    freopen("Output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

void Search(int cur, int cnt){
    //이부분 풀이 참조
    if(cnt > g_cnt){
        return;
    }
    //끝

    if(cur == g_b){
        if(cnt < g_cnt){
            g_cnt = cnt;
        }
        return;
    }

    if(cur < g_b){
        Search(cur + 1, cnt + 1);
        Search(cur + 5, cnt + 1);
        Search(cur + 10, cnt + 1);
    }
    else{
        Search(cur - 1, cnt + 1);
        Search(cur - 5, cnt + 1);
        Search(cur - 10, cnt + 1);
    }
}

int main()
{
    Input();
    Search(g_a, 0);
    Output();
    return 0;
}
