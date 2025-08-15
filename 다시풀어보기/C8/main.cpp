#include <stdio.h>
#include <queue>

using namespace std;

struct ELEMENT{
    int temp;
    int cnt;
};

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

void Search(){
    ELEMENT cur;
    queue <ELEMENT> q;

    q.push((ELEMENT){g_a,0});

    while(!q.empty()){
        cur = q.front();
        q.pop();

        if(cur.temp == g_b)
            break;

        if(cur.temp < g_b){
            q.push((ELEMENT){cur.temp + 10, cur.cnt + 1});
            q.push((ELEMENT){cur.temp + 5, cur.cnt + 1});
            q.push((ELEMENT){cur.temp + 1, cur.cnt + 1});
        }else{
            q.push((ELEMENT){cur.temp - 10, cur.cnt + 1});
            q.push((ELEMENT){cur.temp - 5, cur.cnt + 1});
            q.push((ELEMENT){cur.temp - 1, cur.cnt + 1});
        }
    }
    printf("bfs  = %d\n", cur.cnt);
}

void mySearch(int cur, int cnt){
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
        mySearch(cur + 1, cnt + 1);
        mySearch(cur + 5, cnt + 1);
        mySearch(cur + 10, cnt + 1);
    }
    else{
        mySearch(cur - 1, cnt + 1);
        mySearch(cur - 5, cnt + 1);
        mySearch(cur - 10, cnt + 1);
    }
}

int main()
{
    Input();
    mySearch(g_a, 0);
    Search();
    Output();
    return 0;
}
