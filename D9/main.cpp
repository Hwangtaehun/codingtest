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

void Input(){
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &g_size, &g_cnt);

    g_car.push_back((ROWCOL){1, 1});
    g_car.push_back((ROWCOL){g_size, g_size});

    for(int i = 0; i < g_cnt; i++){
        int m_x, m_y;
        scanf("%d %d", &m_x, &m_y);
        g_case.push_back((ROWCOL){m_x, m_y});
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

int main()
{
    Input();
    mySolve(0, 0);
    Output();
    return 0;
}
