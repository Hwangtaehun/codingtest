#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_cost, g_cnt = 0x0FFFFFFF;
vector<int> g_coin;

//Solve
#include <memory.h>

int m, n, coin[10], DT[10001];

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_cost, &g_size);

    for(int i = 0; i < g_size; i++){
        scanf("%d", &coin[i]);
        g_coin.push_back(coin[i]);
    }

    fclose(stdin);

    m = g_cost;
    n = g_size;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

void mySolve(int index, int rest, int cnt){
    if(index >= g_size){
        return;
    }

    if(rest <= 0){
        if(rest == 0 && cnt < g_cnt){
            g_cnt = cnt;
        }
        return;
    }

    for(int i = 0; g_coin[index] * i <= rest; i++){
        mySolve(index + 1, rest - (g_coin[index] * i), cnt + i);
    }
}

int Min(int a, int b){return a > b ? b : a;}

void Solve(){
    for(int i = 0; i < n; i++){
        DT[coin[i]] = 1;
    }

    for(int i = coin[0]; i <= m; i++){
        if(DT[i] == 0){
            DT[i] = 987654321;
            for(int j = 0; j < n; j++){
                if(i - coin[j] > 0){
                    DT[i] = Min(DT[i], DT[i - coin[j]] + 1);
                }
            }
        }
    }
    printf("%d\n", DT[m]);
}

int f(int c){
    if(c == m)
        return DT[c] = 0;
    if(DT[c] == 0){
        DT[c] = 987654321;
        for(int i = 0; i < n; i++){
            if(c + coin[i] <= m){
                DT[c] = Min(DT[c], f(c + coin[i]) + 1);
            }
        }
    }

    return DT[c];
}

int f1(int c){
    for(int i = 0; i < n; i++){
        if(coin[i] == c){
            return 1;
        }
    }

    if(DT[c] == 0){
        DT[c] = 987654321;

        for(int i = 0; i < n; i++){
            if(c - coin[i] > 0){
                DT[c] = Min(DT[c], f1(c - coin[i]) + 1);
            }
        }
    }

    return DT[c];
}

int main()
{
    Input();
    Solve();
    memset(DT, 0, sizeof(DT));
    printf("%d\n", f(0));
    memset(DT, 0, sizeof(DT));
    printf("%d\n", f1(m));
    mySolve(0, g_cost, 0);
    Output();
    return 0;
}
