#include <cstdio>
#include <vector>
#define SIZE 2

using namespace std;

struct ROWCOL{
    int x;
    int y;
};

vector<ROWCOL> g_case, g_car;
int g_size, g_cnt, g_dis;

//solve
#include <cmath>
int di[1002][1002], data[1002][2], n, m, debugCnt, ans = 0x0fffffff;

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_size, &g_cnt);
    n = g_size, m = g_cnt;

    g_car.push_back((ROWCOL){1, 1});
    g_car.push_back((ROWCOL){g_size, g_size});

    data[0][0] = data[0][1] = 1;
    data[1][0] = data[1][1] = n;

    for(int i = 0; i < g_cnt; i++){
        scanf("%d %d", &data[i+2][0], &data[i+2][1]);
        g_case.push_back((ROWCOL){data[i+2][0], data[i+2][1]});
    }

    fclose(stdin);
}

void Output(){
    freopen("output.txt", "w", stdout);
    printf("%d", g_dis);
    fclose(stdout);
}

int Nature(int num){
    return num > 0 ? num : -num;
}

void mySolve(int i, int dis){
    int m_dis1, m_dis2;

    if(i == g_cnt){
        g_dis = dis;
        return;
    }

    m_dis1 = Nature(g_car[0].x - g_case[i].x) + Nature(g_car[0].y - g_case[i].y);
    m_dis2 = Nature(g_car[1].x - g_case[i].x) + Nature(g_car[1].y - g_case[i].y);

    if(m_dis1 < m_dis2){
        g_car[0].x = g_case[i].x;
        g_car[0].y = g_case[i].y;
        mySolve(i + 1, dis + m_dis1);
    }else{
        g_car[1].x = g_case[i].x;
        g_car[1].y = g_case[i].y;
        mySolve(i + 1, dis + m_dis2);
    }
}

void ArrayPrn(){
    int a, b;

    for(a = 0; a < m + 2; a++){
        for(b = 0; b < 2; b++){
            printf("%3d", data[a][b]);
        }
        printf("\n");
    }
    printf("\n");

    for(a = 0; a < m + 2; a++){
        for(b = 0; b < 2; b++){
            printf("%3d", di[a][b]);
        }
        printf("\n");
    }
    printf("\n");
}

void Distance(){
    int a, b;
    for(a = 0; a < m + 2; a++){
        for(b = 0; b < m + 2; b++){
            di[a][b] = abs(data[a][0] - data[b][0]) + abs(data[a][1] - data[b][1]);
        }
    }
}

void Greedy(int a, int b){
    ans = 0;
    for(int i = 2; i < m + 2; i++){
        if(di[i][a] > di[i][b]){
            ans += di[i][b];
            b = i;
        }
        else{
            ans += di[i][a];
            a = i;
        }
    }
}

void Solve(int a, int b, int d){
    int next = (a > b ? a : b) + 1;

    if( d > ans){
        return;
    }

    printf("%d %d %d %3d %3d\n", a, b, next, d, di[a][next]);
    debugCnt++;
    if(next >= m + 2){
        if(d < ans){
            ans = d;
        }
        return;
    }
    Solve(next, b, d + di[a][next]);
    Solve(a, next, d + di[b][next]);
}

int main()
{
    Input();
    Distance();
    ArrayPrn();
    Greedy(0, 1);
    Solve(0, 1, 0);
    printf("%d\n", ans);
    printf("debugCnt = %d\n", debugCnt);
    mySolve(0, 0);
    Output();
    return 0;
}
