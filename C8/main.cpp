#include <stdio.h>

using namespace std;

int g_a, g_b, g_cnt = 0x7FFFFFFF;

void Input(){
    freopen("Input.txt", "r", stdin);
    scanf("%d %d", &g_a, &g_b);
    fclose(stdin);
}

void Search(int cur, int pri, int cnt){
    int m_cur = cur + pri;

    printf("m_cur = %d, cnt = %d\n", m_cur, cnt);

    //요부분 추가 중요
    if(cnt > g_cnt){
        return;
    }

    if(m_cur == g_b){
        if(cnt < g_cnt){
            g_cnt = cnt;
        }
        return;
    }

    if(m_cur < g_b){
        Search(m_cur, 1, cnt + 1);
        Search(m_cur, 5, cnt + 1);
        Search(m_cur, 10, cnt + 1);
    }
    else{
        Search(m_cur, -1, cnt + 1);
        Search(m_cur, -5, cnt + 1);
        Search(m_cur, -10, cnt + 1);
    }
}

int main()
{
    Input();
    if(g_a < g_b){
        Search(g_a, 1, 1);
        Search(g_a, 5, 1);
        Search(g_a, 10, 1);
    }
    else{
        Search(g_a, -1, 1);
        Search(g_a, -5, 1);
        Search(g_a, -10,1);
    }
    printf("g_cnt = %d\n", g_cnt);
    return 0;
}
