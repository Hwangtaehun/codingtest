#include <cstdio>
#include <vector>

using namespace std;

int g_size, g_cost, g_cnt = 0x0FFFFFFF;
vector<int> g_coin;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_cost, &g_size);
    g_coin.resize(g_size);
    for(int i = 0; i < g_size; i++){
        scanf("%d", &g_coin[i]);
    }
    fclose(stdin);
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

int main()
{
    Input();
    mySolve(0, g_cost, 0);
    Output();
    return 0;
}
