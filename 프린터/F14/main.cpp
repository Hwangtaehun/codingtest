#include <cstdio>
#include <vector>

using namespace std;

struct ROWCOL{
    int x;
    int y;
};

int g_size, g_cnt, g_dis = 0;
vector<ROWCOL> g_route; // -1:place
vector<ROWCOL> g_car;

//solve
#include <memory.h>
#define INF 0x3f3f3f

int DT[1100][1100], E[1010][2], n, m, ans = INF;

void Input(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &g_size, &g_cnt);
    for(int i = 2; i < g_cnt + 2; i++){
        scanf("%d %d", &E[i][0], &E[i][1]);
        g_route.push_back((ROWCOL){E[i][0], E[i][1]});
    }
    fclose(stdin);

    g_car.push_back((ROWCOL){1, 1});
    g_car.push_back((ROWCOL){g_size, g_size});

    n = g_size;
    m = g_cnt;
    E[0][0] = E[0][1] = 1;
    E[1][0] = E[1][1] = n;
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_dis);
    fclose(stdout);
}

int Abs(int a){
    return a > 0 ? a : -a;
}

int Min(int a, int b){
    return a > b ? b : a;
}

int dis(int a, int b){
    return Abs(E[a][0] - E[b][0]) + Abs(E[a][1] - E[b][1]);
}

int f1(int a, int b){
    int next = (a > b ? a : b) + 1;

    if(next >= m + 2)
        return 0;

    return Min(f1(next, b) + dis(a, next), f1(a, next) + dis(b, next));
}

int f2(int a, int b){
    if(DT[a][b] == 0){
        int next = (a > b ? a : b) + 1;

        if(next >= m + 2){
            DT[a][b] = 0;
        }else{
            DT[a][b] = Min(f2(next, b) + dis(a, next), f2(a, next) + dis(b, next));
        }
    }
    return DT[a][b];
}

void Solve(){
    memset(DT, 0x3f, sizeof(DT));
    DT[0][1] = 0;

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < m + 1; j++) {

            int next = (i > j ? i : j) + 1;
            if (next > m + 1) continue;

            int dist_i_next = (i == 0) ? dis(0, next) : dis(i, next);
            DT[next][j] = Min(DT[next][j], DT[i][j] + dist_i_next);

            int dist_j_next = (j == 0) ? dis(1, next) : dis(j, next);
            DT[i][next] = Min(DT[i][next], DT[i][j] + dist_j_next);
        }
    }

    ans = INF;
    for (int i = 0; i < m + 1; i++) {
        ans = Min(ans, Min(DT[i][m + 1], DT[m + 1][i]));
    }
    printf("%d\n", ans);
}

void mySolve(){
    for(int i = 0; i < g_route.size(); i++){
        int m_dis1 = g_car[0].x - g_route[i].x + g_car[0].y - g_route[i].y;
        int m_dis2 = g_car[1].x - g_route[i].x + g_car[1].y - g_route[i].y;
        m_dis1 = Abs(m_dis1);
        m_dis2 = Abs(m_dis2);

        if(m_dis1 < m_dis2){
            g_dis += m_dis1;
            g_car[0].x = g_route[i].x;
            g_car[0].y = g_route[i].y;
        }else{
            g_dis += m_dis2;
            g_car[1].x = g_route[i].x;
            g_car[1].y = g_route[i].y;
        }
    }
}

int main()
{
    Input();
    printf("%d\n", f1(0, 1));
    printf("%d\n", f2(0, 1));
    memset(DT, 0, sizeof(DT));
    Solve();
    mySolve();
    Output();
    return 0;
}
