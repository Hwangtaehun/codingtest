#include <cstdio>
#include <cmath>
#define DIS 10
#define SIZE 2

using namespace std;

int g_place, g_trans, g_gas = 0x0fffffff, **g_data;
bool *g_visitd;

//solve
int n, k, visit[11], dmin=0x0fffffff;
struct airport{
    int x;
    int y;
} a[11];

void Input()
{
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_place, &g_trans);
    n = g_place;
    k = g_trans;

    g_data = new int*[g_place];
    g_visitd = new bool[g_place];

    for(int i = 0; i < g_place; i++){
        g_data[i] = new int[SIZE];
        g_visitd[i] = false;
    }

    a[0].x = 0, a[0].y = 0;

    for(int i = 0; i < g_place; i++){
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
        a[i+1].x = g_data[i][0];
        a[i+1].y = g_data[i][1];
    }
    fclose(stdin);

    a[n+1].x = 10000, a[n+1].y = 10000;
    visit[0] = 1;
}

int Distance(int p1, int p2)
{
    return (a[p1].x - a[p2].x) * (a[p1].x - a[p2].x) + (a[p1].y - a[p2].y) * (a[p1].y - a[p2].y);
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

void Solve(int p, int c, int d){
    int d2;
    if(c == k){
        d2 = Distance(p, n + 1);
        if(d < d2)
            d = d2;
        if(dmin > d)
            dmin = d;
        return;
    }

    for(int i = 0; i <= n+1; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            d2 = Distance(p, i);
            if(d < d2)
                d = d2;
            Solve(i, c+1, d);
            visit[i] = 0;
        }
    }
}

void mySolve(int cnt, int gas, int x, int y){
    if(cnt == g_trans){
        if(gas < Lqude(x, y, 10000, 10000)){
            gas = Lqude(x, y, 10000, 10000);
        }

        if(gas < g_gas){
            g_gas = gas;
        }
        return;
    }


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
    Solve(0, 0, 0);
    printf("%.f\n", ceil(sqrt(dmin)/10));
    Output();
    return 0;
}
