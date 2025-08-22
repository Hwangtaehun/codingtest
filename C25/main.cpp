#include <cstdio>
#include <cmath>
#define DIS 10
#define SIZE 2

using namespace std;

int g_place, g_trans, g_gas = 0x0fffffff, **g_data;
bool *g_visitd;

void Input()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_place, &g_trans);
    g_data = new int*[g_place];
    g_visitd = new bool[g_place];

    for(int i = 0; i < g_place; i++){
        g_data[i] = new int[SIZE];
        g_visitd[i] = false;
    }

    for(int i = 0; i < g_place; i++){
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
    }

    fclose(stdin);
}

int Lqude(int s_x, int s_y, int g_x, int g_y){
    double m_dis = sqrt(pow((g_x - s_x), 2) + pow((g_y - s_y), 2));
    double m_gas = ceil(m_dis / (double)DIS);
    return int(m_gas);
}

void TestPrint(){
    for(int i = 0; i < g_place; i++){
        printf("%d %d\n", g_data[i][0], g_data[i][1]);
    }
}

void mySolve(int cnt, int gas, int x, int y){
    if(cnt >= g_trans){
        if(cnt == g_trans){
            if(gas < Lqude(x, y, 10000, 10000)){
                gas = Lqude(x, y, 10000, 10000);
            }

            if(gas < g_gas){
                g_gas = gas;
            }
        }
        return;
    }

    //while(1){
        for(int i = 0; i < g_place; i++){
            if(!g_visitd[i]){
                g_visitd[i] = true;
                if(gas < Lqude(x, y, g_data[i][0], g_data[i][1])){
                    gas = Lqude(x, y, g_data[i][0], g_data[i][1]);
                }
                mySolve(cnt + 1, gas, g_data[i][0], g_data[i][1]);
                g_visitd[i] = false;
            }
        }
    //}
}

void Output()
{
    freopen("output.txt", "w", stdout);
    printf("%d", g_gas);
    fclose(stdout);
}

int main()
{
    Input();
    //TestPrint();
    mySolve(0, 0, 0, 0);
    Output();
    return 0;
}
