#include <cstdio>
#include <vector>

using namespace std;

int g_cost, g_size, g_cnt = 0x7fffffff;
vector<int> g_coin;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_cost, &g_size);
    for(int i = 0; i < g_size; i++){
        int m_coin;
        scanf("%d", &m_coin);
        g_coin.push_back(m_coin);
    }
    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_cnt);
    fclose(stdout);
}

void TestPrint(){
    printf("g_cost = %d, g_size = %d\n", g_cost, g_size);
    for(int i = 0; i < g_coin.size(); i++){
        printf("%d ", g_coin[i]);
    }
    printf("\n");
}

void mySolve(int index, int rest, int cnt){
    if(cnt > g_cnt || index >= g_size){
        return;
    }

    if(rest == 0){
        if(cnt < g_cnt){
            g_cnt = cnt;
        }
        return;
    }

    for(int i = 0; g_coin[index] * i <= rest; i++){
        mySolve(index + 1, rest - g_coin[index] * i, cnt + i);
    }
}

int main()
{
    Input();
    //TestPrint();
    mySolve(0, g_cost, 0);
    Output();
    return 0;
}
