#include <cstdio>
#include <vector>
#include <cmath>

#define ROWCOL 2
#define LETER 10

using namespace std;

int g_size, g_via, g_min = 0x0FFFFFFF;
vector <bool> g_visit;
vector<vector <int> > g_data;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_via);

    g_data.resize(g_size);
    g_visit.resize(g_size);

    for(int i = 0; i < g_size; i++){
        g_data[i].resize(ROWCOL);
        scanf("%d %d", &g_data[i][0], &g_data[i][1]);
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_min);
    fclose(stdout);
}

int Gas(int dis_x, int dis_y){
    double m_dis = sqrt(pow(dis_x, 2) + pow(dis_y, 2));
    return (int)ceil(m_dis / 10);
}

int Abs(int num){
    return num < 0 ? -num : num;
}

int Count(){
    int cnt = 0;

    for(int i = 0; i < g_size; i++){
        if(g_visit[i] == 1){
            cnt++;
        }
    }

    return cnt;
}

void Solve(int x, int y, int gas){
    int dis_x, dis_y, m_gas;

    if(Count() == g_via){
        dis_x = Abs(10000 - x);
        dis_y = Abs(10000 - y);
        m_gas = Gas(dis_x, dis_y);

        if(gas < m_gas){
            gas = m_gas;
        }

        if(gas < g_min){
            g_min = gas;
        }
        return;
    }

    for(int i = 0; i < g_size; i++){
        if(g_visit[i] == 0){
            dis_x = Abs(g_data[i][0] - x);
            dis_y = Abs(g_data[i][1] - y);
            m_gas = Gas(dis_x, dis_y);

            if(m_gas < gas){
                m_gas = gas;
            }

            g_visit[i] = 1;
            Solve(g_data[i][0], g_data[i][1], m_gas);
            g_visit[i] = 0;
        }
    }
}

int main()
{
    Input();
    Solve(0, 0, 0);
    Output();
    return 0;
}
