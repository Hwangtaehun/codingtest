#include <cstdio>
#include <vector>

using namespace std;

int g_money, g_size, g_min = 0x7fffffff;
vector<int> g_coin;

//solve
int n, m, debugCnt, coin[10], ans = 0x7FFFFFFF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_money, &g_size);
    m = g_money;
    n = g_size;

    for(int i = 0; i < g_size; i++){
        scanf("%d", coin + i);
        g_coin.push_back(coin[i]);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

void mySolve(int money, int index, int cnt){
    if(money == 0){
        if(cnt < g_min){
            g_min = cnt;
        }
        return;
    }

    if(index >= g_size){
        return;
    }

    for(int i = 0; g_coin[index] * i <= money; i++){
        mySolve(money - g_coin[index] * i, index + 1, cnt + i);
    }
}

int Greedy(int mon){
    int cnt = 0;
    for(int i = n-1; i >= 0; i--){
        cnt += mon/coin[i];
        mon %= coin[i];
        printf("mon=%d, coin=%d, cnt=%d\n", mon, coin[i], cnt);
    }

    if(mon == 0){
        ans = cnt;
    }

    return mon;
}

void Solve1(int mon, int cnt){
    if(cnt > ans)
        return;

    if(mon > m)
        return;

    debugCnt++;

    if(mon == m){
        if(cnt < ans)
            ans = cnt;
        return;
    }

    for(int i = 0; i < n; i++){
        Solve1(mon + coin[i], cnt + 1);
    }
}

//기존과 같음
void Solve2(int mon, int k, int cnt){
    if(cnt > ans)
        return;

    if(k == n || mon > m)
        return;

    debugCnt++;

    if(mon == m){
        printf("mon = %d, k = %d, cnt = %d\n", mon, k, cnt);

        if(ans > cnt){
            ans = cnt;
        }

        return;
    }

    for(int i = 0; mon + coin[k] * i <= m; i++){
        Solve2(mon + coin[k] * i, k + 1, cnt + i);
    }
}

int main()
{
    Input();

    if(Greedy(m) != 0){
        Solve1(0, 0);
        //Solve2(0, 0, 0);
    }

    printf("%d\n", ans);
    printf("debugCnt = %d\n", debugCnt);

    mySolve(g_money, 0, 0);
    Output();
    return 0;
}
