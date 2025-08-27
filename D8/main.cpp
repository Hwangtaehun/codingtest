#include <cstdio>
#include <vector>

using namespace std;

int g_money, g_size, g_min = 0x7fffffff;
vector<int> g_coin;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_money, &g_size);
    for(int i = 0; i < g_size; i++){
        int n;
        scanf("%d", &n);
        g_coin.push_back(n);
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

int main()
{
    Input();
    mySolve(g_money, 0, 0);
    Output();
    return 0;
}
